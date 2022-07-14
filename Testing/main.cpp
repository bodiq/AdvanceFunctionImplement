#include <iostream>
#include <memory.h>
#include <mm_malloc.h>
#include <functional>

template<typename...>
class function;

template<typename Res, typename... Args>
class function<Res(Args...)>
{
public:
    template<typename Functor>
    function(Functor f) :
    invoke_(reinterpret_cast<Invoke_ptr> (invokeF<Functor>)),
    create_(reinterpret_cast<Create_ptr> (createF<Functor>)),
    delete_(reinterpret_cast<Delete_ptr> (deleteF<Functor>)),
    data_ptr(new char[sizeof(Functor)]),
    data_size(sizeof(Functor))
    {
        create_(data_ptr.get(), reinterpret_cast<void*>(&f));
    }
    function(const function &func)
    {
        this->invoke_ = func.invoke_;
        this->create_ = func.create_;
        this->delete_ = func.delete_;
        this->data_size = func.data_size;
        if(data_ptr != nullptr)
        {
            data_ptr.reset(new char[data_size]);
            create_(data_ptr.get(), func.data_ptr.get());
        }
    }

    Res operator()(Args&&... args)
    {
        return invoke_(data_ptr.get(), std::forward<Args>(args)...);
    }

    ~function()
    {
        if(data_ptr != nullptr)
        {
            delete_(data_ptr.get());
        }
    }

private:
    using Invoke_ptr = Res(*)(void*, Args&&...);
    using Create_ptr = void(*)(void*, void*);
    using Delete_ptr = void(*)(void*);

    Invoke_ptr invoke_;
    Create_ptr create_;
    Delete_ptr delete_;

    std::unique_ptr<char[]> data_ptr;
    size_t data_size;

    template<typename Functor>
    Res invokeF(Functor *f, Args&&... args)
    {
        return (*f)(std::forward<Args>(args)...);
    }

    template<typename Functor>
    void createF(Functor *dst, Functor *src)
    {
        dst = new Functor(*src);
    }

    template<typename Functor>
    void deleteF(Functor *f)
    {
        f->~Functor();
    }
};

int main()
{
    int i = 0;

    auto l = [] (std::string &a) { return a; };

    std::function<std::string(std::string&)> d = [] (std::string &a) -> decltype(auto) { return a; };

    std::string alex = "alex";

    d(alex);

    l(alex);


    return 0;
}

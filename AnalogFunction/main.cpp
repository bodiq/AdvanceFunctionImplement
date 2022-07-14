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
    function() :
            invoke_(nullptr),
            create_(nullptr),
            delete_(nullptr),
            data_ptr(nullptr),
            data_size(0) {}

    template<typename Functor>
    function(Functor f) :
            invoke_(reinterpret_cast<Invoke_ptr> (invokeF<Functor>)),
            create_(reinterpret_cast<Create_ptr> (createF<Functor>)),
            delete_(reinterpret_cast<Delete_ptr> (deleteF<Functor>)),
            data_ptr(new char[sizeof(Functor)]),
            data_size(sizeof(Functor))
    {
        create_(data_ptr.get(), reinterpret_cast<char*>(&f));
    }
    function(const function &func) :
            invoke_(func.invoke_),
            create_(func.create_),
            delete_(func.delete_),
            data_size(func.data_size)
    {
        if(invoke_ != nullptr)
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
    static Res invokeF(Functor *f, Args&&... args)
    {
        return (*f)(std::forward<Args>(args)...);
    }

    template<typename Functor>
    static void createF(Functor *dst, Functor *src)
    {
        new (dst) Functor(*src);
    }

    template<typename Functor>
    static void deleteF(Functor *f)
    {
        f->~Functor();
    }
};

class A
{
public:
    A() = default;
};

class B : public A
{
public:
    B() = default;
};

int main()
{
    int i = 0;

    auto l = [] (std::string &a) { return a; };

    std::function<std::string(std::string&)> d = [] (std::string &a) -> decltype(auto) { return a; };

    std::string alex = "alex";

    std::cout << d(alex) << std::endl;

    std::cout << l(alex) << std::endl;

    auto fn = [i](std::string const& s) mutable
    {
        std::cout << ++i << ". " << s << std::endl;
    };
    fn("first");                                   // 1. first
    fn("second");                                  // 2. second

    // construct from lambda
    function<void(std::string const&)> f(fn);
    f("third");                                    // 3. third

    // copy from another function
    function<void(std::string const&)> g(f);
    f("forth - f");                                // 4. forth - f
    g("forth - g");                                // 4. forth - g

    // capture and copy non-trivial types like std::string
    std::string x("xxxx");
    function<void()> h([x]() { std::cout << x << std::endl; });
    h();

    function<void()> k(h);


    A a;
    B b;

    A *c = static_cast<B*>(&b);

    return 0;

}

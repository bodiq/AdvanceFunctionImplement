#include <iostream>
#include <exception>

void DoSmth(bool err, bool err1, bool err2)
{
    if(err)
    {
        throw 101;
    }
    else if(err1)
    {
        throw "FuckThisShit";
    }
    else if(err2)
    {
        throw std::string("This is string error");
    }
}

class CanGoWrong : public std::exception
{
public:
    virtual const char* what() const _NOEXCEPT
    {
        std::cout << "Something wrong" << std::endl;
    }
};

class Test
{
public:
    void SomeThing()
    {
        throw CanGoWrong();
    }
};

int main()
{
/*    int choice = 0;
    std::cout << "Enter the err you want to call: ";
    std::cin >> choice;*/
    Test test;
    try
    {
/*        switch(choice)
        {
            case 1: DoSmth(1, 0, 0); break;
            case 2: DoSmth(0, 1, 0); break;
            case 3: DoSmth(0, 0, 1); break;
            default: break;
        }*/
        test.SomeThing();
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "Error number: " << e.what() << std::endl;
    }
    catch (int e)
    {
        std::cout << e << std::endl;
    }
    catch (const CanGoWrong &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    std::cout << "Code is running" << std::endl;
    return 0;
}

#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <forward_list>

class A
{
public:
    A()
    {
        m_buff = new int[SIZE];
        std::cout << "Constructor" << std::endl;
    }
    A(const A &a)
    {
        m_buff = new int[sizeof(a.m_buff) / sizeof(a.m_buff[0])];
        for(size_t i = 0; i < sizeof(a.m_buff) / sizeof(a.m_buff[0]); i++)
        {
            m_buff[i] = a.m_buff[i];
        }
        std::cout << "Copy Constructor" << std::endl;
    }
    A &operator=(const A &a)
    {
        if(this == &a)
        {
            return *this;
        }
        delete []m_buff;

        m_buff = new int[sizeof(a.m_buff) / sizeof(a.m_buff[0])];
        for(size_t i = 0; i < sizeof(a.m_buff) / sizeof(a.m_buff[0]); i++)
        {
            m_buff[i] = a.m_buff[i];
        }
        std::cout << "Assigment" << std::endl;
        return *this;
    }
    A &operator=(A &&a)
    {
        delete []m_buff;
        m_buff = a.m_buff;
        a.m_buff = nullptr;
        std::cout << "Move assigment operator" << std::endl;
    }
    A(int in)
    {
        m_buff = new int[SIZE];
        for(size_t i = 0; i < SIZE; i++)
        {
            m_buff[i] = in * 7;
        }
        std::cout << "Inititaling" << std::endl;
    }
    A(int m_num, int m_num1) : num(m_num), num1(m_num1)
    {
        m_buff = new int[SIZE];
        std::cout << "Contructor with nums" << std::endl;
    }
    A(A &&a)
    {
        m_buff = a.m_buff;
        std::cout << "Movsng Constr" << std::endl;

        a.m_buff = nullptr;

    }
    int get()
    {
        return num + num1;
    }
    ~A()
    {
        if(m_buff != nullptr)
        {
            delete []m_buff;
        }
        std::cout << "Destructor" << std::endl;
    }

private:
    int num1;
    int num;
    int *m_buff;
    static const int SIZE = 100;
};

A getA()
{
    return A();
}

/*void check(const int &a)
{
    std::cout << "Something L" << a << std::endl;
}

void check(int &&a)
{
    std::cout << "Something R" << a << std::endl;
}*/

class Test
{
public:
    int add(int a, int b, int c) {
        std::cout << a << ", " << b << ", " << c << std::endl;
        return a + b + c;
    }
};

int func(std::function<int(int, int, int)> aleop)
{
    return aleop(4, 6, 1);
}

template<typename T>
void check(T& a)
{
    std::cout << "Lvalue" << std::endl;
}

template<typename T>
void check(T &&a)
{
    std::cout << "RValue" << std::endl;
}

template<typename T>
void Outer(T &&a) // Чому при темплейтах можна вставляти в параметр для rvalue lvalue
{
    std::cout << "Alex" << std::endl;
    check(std::forward<T>(a));
}

template<typename T>
auto foo(T value) -> decltype(auto)
{
    return value;
}

struct a
{
    bool bol;
    double d;
    int a;
    int b;
    int c;
};

int main()
{
    a aa;

    std::cout << sizeof(a) << std::endl;

    return 0;
}

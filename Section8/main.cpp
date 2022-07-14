#include <iostream>
#include <typeinfo>

template <class T, class S>
auto test(T val, S val1) -> decltype(auto)
{
    return val + val1;
}

template<>
auto test<const char*, const char *>(const char *val, const char *val1) -> decltype(auto)
{
    char *temp = new char[strlen(val) + strlen(val1) + 1];
    std::strcpy(temp, val);
    std::strcpy(temp + strlen(val), val1);
    return temp;
}

int get()
{
    return 999;
}

auto test2()
{
    return get();
}


int main()
{
    const std::string a = "alex";
    const std::string b = "Beka";

    auto resu = test(a, b);
    std::cout << test("alex", "Oleg") << std::endl;

    std::cout << test2() << std::endl;
    return 0;
}

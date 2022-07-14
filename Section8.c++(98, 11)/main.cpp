#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


void lab(std::function<bool(std::string&)> check)
{
    std::string alpa = "alexa";
    std::cout << check(alpa) << std::endl;
}


int main()
{
    std::vector<int> a{1, 3, 6, 8, 2};
    int size = 5;

    int count = std::count_if(a.begin(), a.end(), [](int a) { return a > 4;});
    std::cout << count << std::endl;

    auto labda = [=] (std::string &a) { return a.size() == size; };

    lab(labda);


    std::function<bool(int, int)> kek = [] (int a, int b) -> bool { int result = a * b; return result < 100; };

    std::cout << kek(10, 2) << std::endl;
    return 0;
}

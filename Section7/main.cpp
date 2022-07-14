#include <iostream>
#include <vector>
#include <string>

int findMax(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}

int main1()
{
    int a = 5;
    int b = 8;

    int result = findMax(a, b);
    std::cout << "Result: " << result << std::endl;

    int (*findMaxMax)(int, int) = findMax;

    result = findMaxMax(10, 15);
    std::cout << "Result: " << result << std::endl;

    return 0;
}

bool match(std::string num)
{
    return num.size() == 3;
}

int count_strings(std::vector<std::string> &texts, bool (*match)(std::string test))
{
    return std::count_if(texts.begin(), texts.end(), match);
}

class Parent
{
public:
    Parent() = default;
    Parent(const Parent &p)
    {
        std::cout << "Copy ";
    }
    virtual void Print()
    {
        std::cout << "Parent" << std::endl;
    }
    virtual ~Parent() = default;
};

class Child : public Parent
{
public:
    Child() = default;
    virtual void Print() override
    {
        std::cout << "Child" << std::endl;
    }
    virtual ~Child() = default;
};

int main()
{
   std::vector<std::string> nums;

    nums.push_back("one");
    nums.push_back("two");
    nums.push_back("three");
    nums.push_back("four");
    nums.push_back("five");
    nums.push_back("six");
    nums.push_back("seven");
    nums.push_back("eight");
    nums.push_back("nine");
    nums.push_back("ten");

    std::for_each(nums.begin(), nums.end(), [] (const std::string &a) { std::cout << match(a) << std::endl; });

    std::cout << count_strings(nums, match) << std::endl;
}

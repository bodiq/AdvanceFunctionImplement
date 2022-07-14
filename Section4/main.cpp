#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <map>

/*
void DisplayOrder(std::list<std::string> &order)
{
    int i = 1;
    if(order.size() <= 0)
    {
        std::cout << "Your order is empty" << std::endl;
        return;
    }
    else
    {
        for(auto it = order.begin(); it != order.end(); it++)
        {
            std::cout << i++ << "). " << *it << std::endl;
        }
    }
}

void DisplayMenu()
{
    std::cout << "1) Add to your order" << std::endl;
    std::cout << "2) Delete from your order" << std::endl;
    std::cout << "3) Show my order" << std::endl;
    std::cout << "4) Exit" << std::endl;
    std::cout << "Enter your choice:";
}

void ChoiceOne(std::list<std::string> &order)
{
    std::string product;
    while(product != "No")
    {
        std::cout << "What do you want to add or type No to get back: ";
        std::cin >> product;
        order.push_back(product);
    }
}

void ChoiceTwo(std::list<std::string> &order)
{
    int choice = 0;
    if(order.size() <= 0)
    {
        std::cout << "Your order is empty to delete something" << std::endl;
        return;
    }
    else
    {
        DisplayOrder(order);
        std::cout << "Enter number your want to delete: ";
        std::cin >> choice;

        std::list<std::string>::iterator it = order.begin();
        while(choice != 0)
        {
            it++;
            choice--;
        }
        it = order.erase(it);
        DisplayOrder(order);
    }
}


int main()
{
    std::cout << "Hello here you can make an order add or delete something from menu." << std::endl;
    int choice = 0;
    std::list<std::string> order;
    while (1)
    {
        DisplayMenu();
        std::cin >> choice;
        switch (choice)
        {
            case 1: ChoiceOne(order); break;
            case 2: ChoiceTwo(order); break;
            case 3: DisplayOrder(order); break;
            case 4: exit(0); break;
            default: break;
        }
    }
    return 0;
}
*/
class Person
{
public:
    Person()
    {
        this->age = 0;
        this->name = "";
    }
    Person(std::string m_name) : name(m_name) {}
    Person(std::string name, int age) : name(name), age(age) {}
    Person(const Person &p)
    {
        name = p.name;
        age = p.age;
    }
    void Print() const
    {
        std::cout << "Name: " << name << std::endl;
    }
    bool operator<(const Person &p) const
    {
        return (name < p.name);
    }
    friend bool comp(const Person &a, const Person &b);
    ~Person()
    {
        std::cout << "Object Destroyed" << std::endl;
    }
private:
    std::string name;
    int age;
};

bool comp(const Person &a, const Person &b)
{
    return (a.name > b.name);
}

int main()
{
    std::map<std::string, std::vector<int>> mama;

    mama["Viletta"].push_back(15);
    mama["Viletta"].push_back(22);
    mama["Alexandra"].push_back(111);

    for(auto it = mama.begin(); it != mama.end(); it++)
    {
        std::cout << "Name: " << it->first << " [ ";
        for(size_t i = 0; i < it->second.size(); i++)
        {
            std::cout << it->second[i] << " ";
        }
        std::cout << " ] " << std::endl;
    }


}
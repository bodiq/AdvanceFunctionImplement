#include <iostream>

struct Test
{
    double d;
    int a;
    int b;
    int c;
    char e;
};

class Base
{
public:
    Base()
    {
        std::cout << "Base Const" << std::endl;
    }
    virtual void Goof() const
    {
        std::cout << "Base" << std::endl;
    }
    virtual ~Base()
    {
        std::cout << "Base Destr" << std::endl;
    }
};

class Enemy : public Base
{
public:
    Enemy()
    {
        std::cout << "Enemy Const" << std::endl;
    }
    virtual void Goof() const override
    {
        std::cout << "Enemy" << std::endl;
    }
    virtual ~Enemy()
    {
        std::cout << "Enemy Destr" << std::endl;
    }
};

class Player : public Base
{
public:
    Player()
    {
        std::cout << "Player Const" << std::endl;
    }
    virtual void Goof() const override
    {
        std::cout << "Player" << std::endl;
    }
    virtual ~Player()
    {
        std::cout << "Player Destr" << std::endl;
    }
};

int main()
{
/*    Test test = {11.2, 62, 33, 8, 102};

    int i = sizeof(Test) / sizeof(int);
    int *ptr = reinterpret_cast<int*>(&test);

    for(int j = 0; j < i; j++)
    {
        std::cout << ptr[j] << std::endl;
    }*/

    Player *player = new Player();

    Base *ActualPlayer = player;

    Base *ActualEnemy = new Enemy();

    Player *p = static_cast<Player*>(ActualEnemy);
    Player *p1 = (Player*)ActualPlayer;


    if(p && p1)
    {
        std::cout << "Laex" << std::endl;
    }
    return 0;
}

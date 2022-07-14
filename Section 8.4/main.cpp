#include "Neste.h"
#include "Neste.cpp"
#include <initializer_list>

int main()
{
    Neste<int> aa(3);

    std::initializer_list<int> a{1, 3, 5, 6};


    aa.add(1);
    aa.add(2);
    aa.add(3);


    for(int aaaa : aa)
    {
        std::cout << aaaa << std::endl;
    }

    return 0;
}

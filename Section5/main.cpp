#include <iostream>
#include "Complex.h"

int main()
{
    Complex c1(2, 3);
    Complex c2(c1);

    std::cout << *c1 + Complex(2.2, 3.1) << c2 << std::endl;
    return 0;
}

#include "Template.h"

int main()
{
    auto i = Template<5>::value;

    std::cout << i << std::endl;
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::fstream file;
    std::string name = "Test.txt";
    std::string line;
    file.open(name, std::ios::in);
    int num = 0;

    if(!file.is_open())
    {
        return 1;
    }

    while (file)
    {
        std::getline(file, line, ':');

        file >> num;
        if(!file)
        {
            break;
        }
        std::cout << line << "---" << num;
    }

    file.close();
    return 0;
}

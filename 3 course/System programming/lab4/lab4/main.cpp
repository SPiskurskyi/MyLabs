#include <iostream>
#include <string>
#include "implementation.h"


int main()
{
    std::string inputString;
    char c;
    std::cout << "Enter the string: ";
    std::getline(std::cin ,inputString);
    std::cout << "Enter the char: ";
    c = getchar();
    int result = implementation(inputString, c);
    std::cout << "Count of entries of '" << c << "' is - " << result << " \n";
    return 0;
}

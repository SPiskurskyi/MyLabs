#include "pch.h"
#include "implementation.h"

int implementation(std::string str, char c)
{
    int sum = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        sum += (str[i] == c) ? i + 1 : 0;
    }

    return sum;
}
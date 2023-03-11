#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char str[32];
	int i;
	printf("Enter the string, please: ");
	gets_s(str, sizeof(str)); 
	i = 0;
	while (str[i] != '.')
	{
		if (isdigit(str[i]))
		{
			for (int j = strlen(str) + 1; j > i + 1; j--)
				str[j] = str[j - 1];
			str[i + 1] = str[i];
			i += 2;
		}
		else
			i++;
	}
	std::cout << str;
	return 0;
}

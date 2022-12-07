#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	const int size = 5;
	int Arr[size];
	for (int i = 0; i < size; i++)
	{
		
		printf("Enter Arr[%d] = ", i);
		scanf_s("%d", &Arr[i]);
	} 
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			if (Arr[i] == Arr[i + j])
				Arr[i + j] = 0;
		}

	}
	for (int i = 0; i < size; i++)
		
		printf("\t New Arr[%d] = %d\n ", i, Arr[i]);
	return 0;
}

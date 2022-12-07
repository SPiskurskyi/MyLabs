#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

void FillArray(int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}
void PrintArray(int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	printf("\n");
}

int main(void)
{
	int size1, size2, number;
	cout << "Enter first array size:";
	scanf_s("%d", &size1);
	cout << "Enter secound array size:";
	scanf_s("%d", &size2);
	int* arr1 = new int[size1];
	int* arr2 = new int[size2];
	FillArray(arr1, size1);
	FillArray(arr2, size2);
	printf("First array \t ");
	PrintArray(arr1, size1);
	printf("Secound array \t");
	PrintArray(arr2, size2);
	printf("====================================================================================================== \n");
	printf("Chose operation \n 1)Array1=Array2 \n 2)Array2=Array1 \n 3)Reverse \n ");
	scanf_s("%d", &number);
	printf("====================================================================================================== \n");
	switch (number)
	{
	case 1:
		delete[]arr1;
		arr1 = new int[size2];
		for (int i = 0; i < size2; i++)
		{
			arr1[i] = arr2[i];
		}
		printf("First array \t ");
		PrintArray(arr1, size1);
		printf("Secound array \t");
		PrintArray(arr2, size2);
		break;
	case 2:
		delete[]arr2;
		arr2 = new int[size1];
		for (int i = 0; i < size1; i++)
		{
			arr2[i] = arr1[i];
		}
		printf("First array \t ");
		PrintArray(arr1, size1);
		printf("Secound array \t");
		PrintArray(arr2, size2);
		break;
	case 3:
	
		for (int i = 0; i < size1 && i < size2; i++) 
		{
			int temp = arr1[i];
			arr1[i] = arr2[i];
			arr2[i] = temp;
		}
		printf("First array \t ");
		PrintArray(arr1, size1);
		printf("Secound array \t");
		PrintArray(arr2, size2);
		break;
	}
	printf("====================================================================================================== \n");
	delete[] arr1;
	delete[] arr2;

}


#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

void func(int** arr, int n)
{
	int n2 = n/2;
	if (n % 2 == 1)
	{
		for (int i = 0; i < n2 + 1 ; i++)
		{
			for (int j = 0; j < i + 1; j++)
			{
				arr[n2 + i][n2 + j] = 0;
				arr[n2 + i][n2 - j] = 0;
				
			}
		}
	}
	
	else if (n % 2 == 0)
	{
		for (int i = 0; i < n2; i++)
		{
			for (int j = 0; j < i + 1; j++)
			{
				arr[n2 + i][n2+j] = 0;
				arr[n2 + i][(n2 - 1) - j] = 0;
			}
		}
	}
	
}
int main()
{
	int** arr, n;
	cout << "Enter order of matrix:";
	cin >> n;
	cout << "-----------------------------------------------------" << endl;
	arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 1;
		}
	}
	func(arr, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << arr[i][j];
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}
#include "Header.h"

int main()
{
	const register int length = 5;
	static double arr1[length];
	static int arr2[length];
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	GenerateArray(arr1, length);
	GenerateArray(arr2, length);
	PrintArray(arr2, length);
	Func(arr2, length);
	PrintArray(arr1, length);
	Func(arr1, length);

}

void GenerateArray(int* arr, int length)
{

	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 100 - 50;
	}
}
void GenerateArray(double* arr, int length)
{

	for (int i = 0; i < length; i++)
	{
		arr[i] = (double)rand() / (double)RAND_MAX * (50 - -50) + -50;
	}
}
////////////////////////////////////////////////////////////////////////////////////
void PrintArray(int* arr, int length)
{

	cout << "\n Arr = ";
	for (int i = 0; i < length; i++)
	{
		cout << "\t" << setw(6) << arr[i] << '|';
	}
	cout << endl << endl;
}
void PrintArray(double* arr, int length)
{

	cout << "\n Arr = ";
	for (int i = 0; i < length; i++)
	{
		cout << "\t"  << setw(6) << round(arr[i] * 10) / 10 << '|';
	}
	cout << endl << endl;
}
////////////////////////////////////////////////////////////////////////////////////
int GetMinId(int* arr, int length)
{
	int PositionOfMinimum = 0;
	for (int index = 1; index < length; index++)
	{
		if (arr[index] < arr[PositionOfMinimum])
			PositionOfMinimum = index;
	}
	return PositionOfMinimum;
}
int GetMinId(double* arr, int length)
{

	int PositionOfMinimum = 0;
	for (int index = 1; index < length; index++)
	{
		if (arr[index] < arr[PositionOfMinimum])
			PositionOfMinimum = index;
	}
	return PositionOfMinimum;
}
////////////////////////////////////////////////////////////////////////////////////
int GetMaxId(int* arr, int length)
{

	int PositionOfMinimum = 0;
	for (int index = 1; index < length; index++)
	{
		if (arr[index] > arr[PositionOfMinimum])
			PositionOfMinimum = index;
	}
	return PositionOfMinimum;
}
int GetMaxId(double* arr, int length)
{

	int PositionOfMinimum = 0;
	for (int index = 1; index < length; index++)
	{
		if (arr[index] > arr[PositionOfMinimum])
			PositionOfMinimum = index;
	}
	return PositionOfMinimum;
}
////////////////////////////////////////////////////////////////////////////////////
void Func(int* arr, int length)
{
	if (GetMaxId(arr, length) > (GetMinId(arr, length)))
	{
		for (int i = GetMinId(arr, length); i < GetMaxId(arr, length); i++)
		{
			if (arr[i] < 0)
			{
				if (arr[i + 1] >= 0)
				{
					if (i + 1 == GetMaxId(arr, length))
					{
						cout << "\tЗнаки чергуються\n";
					}
					else if (arr[i + 2] < 0)
					{
						cout << "\tЗнаки чергуються\n";
					}
					break;
				}
				break;
			}
		}
	}
	if (GetMaxId(arr, length) < (GetMinId(arr, length)))
	{
		for (int i = GetMaxId(arr, length); i < GetMinId(arr, length); i++)
		{
			if (arr[i] >= 0)
			{
				if (arr[i + 1] < 0)
				{
					if (i + 1 == GetMinId(arr, length))
					{
						cout << "\tЗнаки чергуються\n";
					}
					else if (arr[i + 2] >= 0)
					{
						cout << "\tЗнаки чергуються\n";
					}
					break;
				}
				break;
			}
		}
	}
}
void Func(double* arr, int length)
{
	if (GetMaxId(arr, length) > (GetMinId(arr, length)))
	{
		for (int i = GetMinId(arr, length); i < GetMaxId(arr, length); i++)
		{
			if (arr[i] < 0)
			{
				if (arr[i + 1] >= 0)
				{
					if (i + 1 == GetMaxId(arr, length))
					{
						cout << "\tЗнаки чергуються\n";
					}
					else if (arr[i + 2] < 0)
					{
						cout << "\tЗнаки чергуються\n";
					}
					break;
				}
				break;
			}
		}
	}
	if (GetMaxId(arr, length) < (GetMinId(arr, length)))
	{
		for (int i = GetMaxId(arr, length); i < GetMinId(arr, length); i++)
		{
			if (arr[i] >= 0)
			{
				if (arr[i + 1] < 0)
				{
					if (i + 1 == GetMinId(arr, length))
					{
						cout << "\tЗнаки чергуються\n";
					}
					else if (arr[i + 2] >= 0)
					{
						cout << "\tЗнаки чергуються\n";
					}
					break;
				}
				break;
			}
		}
	}
}

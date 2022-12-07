#include <iostream>
#include <ctime>
using namespace std;
const int m = 2, n = 5; 
void FillMatrix(int x[][n]); 
void PrintMatrix(int x[][n]); 
int main()
{
	int Arr[m][n], k;
	srand(time(NULL));
	FillMatrix(Arr); 
	PrintMatrix(Arr); 
	k = n / 2;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			Arr[i][n - 1 - j] = Arr[i][j];
		}
	}
	PrintMatrix(Arr); 
}
void FillMatrix(int x[][n]) 
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			x[i][j] = rand() % 20;
		}
}
void PrintMatrix(int x[][n]) 
{
	int i, j;
	printf("\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%8d\t", x[i][j]);
		printf("\n");
	}
}
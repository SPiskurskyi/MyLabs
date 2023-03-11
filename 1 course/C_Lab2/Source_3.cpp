#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int x = 0;
	double e = 0, result=1, member=1;         
	printf("Enter x, e \n");
	scanf_s("%d %f", &x, &e);
	for (int i = 1; member >= e; i++)      
	{
		member *= x * x;                    
		member /= 2 * i * (2 * i - 1);       
		result += member;                  
	
	}
	printf("%f", result);                      
	

}
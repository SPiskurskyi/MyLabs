#include <iostream>
using namespace std;
int main()
{
	int k = 0, n; 
	float res=0, nn; 
	printf("Enter n:");
	scanf_s("%d", &n);       
	for (int i=0;i<n; i++)  
	{
		scanf_s("%f", &nn);        
		if (k == 0)      
		{
			res += nn;     
			k++;           
		}
		else            
		{
			k = 0;         
		}
	}
	printf("Result is %f", res);       
	
	
}


#define _USE_MATH_DEFINES					
#include <math.h>  
#include <iostream>      
#include <cmath>
using namespace std;                       
float MyFunc(float c, float d, float n);  

int main()
{
	float c , d, r;                        
	printf("Input c\n");
	scanf_s("%f", &c);
	printf("Input d\n");
	scanf_s("%f", &d);
	r = MyFunc(c, d, 200);             
	r = r * r;
	r += MyFunc(0, M_PI, 200);
	printf("RESULT IS = %f ", r);
}
float MyFunc(float a, float b, float n)         
{
	float h, r = 0;
	h = (b - a) / n;
	for (int i = 0; i < n; i++) {           
		r += a + h * i;
	}
	r *= h;
	return r;                               
}



#include "stdafx.h"
#include <stdio.h>
//#define _USE_MATH_DEFINES 
#include <cmath>
#define M_PI 3.14 

int _tmain(int argc, _TCHAR* argv[])
{
	float r, h, l, V, S;
 printf("input r: ");
 scanf_s("%f", &r);
 printf("input h: ");
 scanf_s("%f", &h);
 l = sqrt((r*r+h*h));
 S = (M_PI*r*l)+(M_PI*r*r);
 V = ((M_PI*r*r*h)/3);
 printf("  V:  %f", V);
 printf("  S:  %f", S);
	return 0;
}


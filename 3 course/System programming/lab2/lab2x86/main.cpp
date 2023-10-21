#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <iostream>


extern "C" double calc(double, float, float);

int main() {
    double a;	  //lf
    float c, d;   //f


    printf("Enter a: ");
    scanf_s("%lf", &a);

    printf("Enter c: ");
    scanf_s("%f", &c);

    printf("Enter d: ");
    scanf_s("%f", &d);


    if (c > d) {
        if ((12 + a - c) == 0 || c == 0) {
            printf("Error: Div by zero!");
            return -1;
        }
        double numerator = (atan(4 * d) / c - 1);
        double denominator = 12 + a - c;
        double res = numerator / denominator;

        printf("C result = %lf", res);
    }
    else {
        if (a * d - 1 == 0) {
            printf("Error: Div by zero!");
            return -1;
        }
        double numerator = atan(c) + c * d - a / 4;
        float denominator = a * d - 1;
        double res = numerator / denominator;
        printf("C result = %lf", res);
    }

    double res = calc(a, c, d);
    printf("\nResult of function calc is: %f\n", res);
    return 0;
}



#include <iostream>

int main()
{
    float x, y;
        printf("input x:");
        scanf_s("%f", &x);
        if (x >= 0) {
            y=x*x;
            printf("y= %f", y);
        }
        else
        {
            printf("the number is negative");
        }

}


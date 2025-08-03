#include<stdio.h>

int main()
{ 
    float x;
    printf("Enter a decimal number : \n");
    scanf("%f", &x);

    int y=x;
    printf("%d \n", y);

    float z=x-y;
    printf(" The fractional part of the decimal number is : %f", z);

    return 0;
}
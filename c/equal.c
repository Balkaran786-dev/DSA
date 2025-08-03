#include<stdio.h>

int main ()
{   
    float a;
    printf("enter number a: ");
    scanf("%f", &a);

    int b;
    b=a;

    printf("%f", a-b);
    return 0;
}
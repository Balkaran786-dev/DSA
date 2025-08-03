#include<stdio.h>
// area of circle
int main ()
{
    int radius;
    printf(" enter the value of radius :");
    scanf("%d", &radius);

    float area= 3.14*radius*radius;
    printf("%f", area);

    return 0;
}
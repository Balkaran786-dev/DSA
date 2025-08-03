#include<stdio.h>

int main()
{ 
    //entering value in centimeters and converting it to meters and kilometers.
    float a;
    printf("Enter value of a in centimeter:");
    scanf("%f",&a);

    printf(" value of a in meters: %f", a*1/100);
    printf(" value of a in kilometers: %f", a*1/100000);
    return 0;
}
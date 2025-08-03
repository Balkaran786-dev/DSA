#include<stdio.h>
#include<math.h>
#define pi 3.14
int main()
{   
    int angle;
    
    printf("Enter the value of angle in degree :");
    scanf("%d",&angle);
    float value=sin(angle*pi/180);

    printf("\n sine of the given angle is:%f",value);
    return 0;
}
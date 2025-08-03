#include<stdio.h>

int main()
{   
    int i,sum=0;
    printf("enter 2 digit number:");
    scanf("%d",&i);
    while( i>0)
    {
        sum=sum + i % 10;
        i= i/10;
    }
        printf(" sum of digits of the number is: %d", sum);
    return 0;
}
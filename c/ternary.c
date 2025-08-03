#include<stdio.h>

int main()
{   
    int a;
    printf("Enter number 1:");
    scanf("%d",&a);

    int b;
    printf("Enter number 2:");
    scanf("%d",&b);

    int c = a>b? a:b;
    printf(" The greater number is: %d",c);
    return 0;
}
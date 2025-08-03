#include<stdio.h>
int main()
{
    int a,b;
    printf("enter number a and b \n");
    scanf("%d %d", &a,&b );

    a=a+b;
    b=a-b;
    a=a-b;

    printf(" the numbers after swaping are \n a:%d  and  b:%d", a,b );
    return 0;
}
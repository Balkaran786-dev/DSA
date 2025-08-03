#include<stdio.h>

int main()
{   
    int a=3, b=4,c;
    c=++a;
    printf("%d%d%d \n", a,b,c);
    c=a++;
    printf("%d%d%d \n", a,b,c);
    c=a++ + ++b;
    printf("%d%d%d \n", a,b,c);

    return 0;
}
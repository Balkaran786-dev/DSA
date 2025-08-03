#include<stdio.h>
#define A 45.91
/* error will be coming because we can't change the value of A 
as we have already declared it as a constant.*/
int main()
{   
    float A= 47.9;
    printf("%f", A);
    return 0;
}
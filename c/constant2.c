#include<stdio.h>

int main()
{   // error will be coming because we have declared apples as a constant value.
   const int apples=23;
   apples=56;
   printf("%d", apples);
    return 0;
}
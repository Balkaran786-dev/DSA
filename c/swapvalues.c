#include<stdio.h>
 // swaping values of a and b.
int main()
{
  int a,b;
  printf("enter number a: ");
  scanf("%d", &a);

  printf("enter number b: ");
  scanf("%d", &b);

  int c;
  c=b;
  b=a;
  a=c;

  printf(" a : %d", a);
  printf(" b : %d", b);
     
     return 0;
}
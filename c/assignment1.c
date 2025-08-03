#include<stdio.h>
// Finding area and perimeter of rectangle.
int main ()
{
   int length,breadth;
   printf("enter the value of length :");
   scanf("%d", & length);

   printf("enter the value of breadth :");
   scanf("%d", & breadth);

   printf(" Area of rectangle : %d ", length*breadth);  // 20
   printf(" perimeter of rectangle : %d ", 2*(length+breadth) );  //18
    return 0;
}
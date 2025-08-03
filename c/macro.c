#include<stdio.h>
#define macro 3.14
#define Apple macro*macro  //we can use macro in definition of other macro
int main()
{   
    int r;
    printf("Enter value of radius:");
    scanf("%d", &r);

    float a=2*macro*r;
    float b=macro*r*r;

    printf("The circumference of circle is: %f \n",a );
    printf("The area of circle is : %f\n",b);
    printf("%f",Apple);
    return 0;
}
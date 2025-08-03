#include<stdio.h>

// percentage of my 12th boards
int main ()
{
   int physics;
   printf("physics marks:");
   scanf("%d", &physics);

   int maths;
   printf("maths marks:");
   scanf("%d", &maths);


   int english;
   printf("english marks:");
   scanf("%d", &english);

   int physicaleducation;
   printf("physicaleducation marks:");
   scanf("%d", &physicaleducation);

   int chemistry;
   printf("chemistry marks:");
   scanf("%d", &chemistry);


   float sum = physics + maths + english + physicaleducation + chemistry;
    printf(" sum of all the marks of all subjects is: %f \n" , sum);
   printf(" percentage of 5 subjects is : %f", sum/5);
    return 0;
}
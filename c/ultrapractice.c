#include<stdio.h>

int main()
{   
    int apples=56;  /* escape sequences...\b: backspace, \n: new line , \t: tab,
    \\: backlslash  \": double qoutes, \': single qoutes, \a: beep sound..*/
   /*            
    printf(" \"The number \bof \b \b \bapples is :%d\" \n ", apples);
    printf("the current numbr of apples is\t \t : %d \n", apples +4);

    int a=56;
    int b=67;
    int c=0; */
 /*
   printf("%d\n", a&&c);
   printf("%d\n", a||b);
   printf("%d\n", !a);
   printf("%d\n", !c);
   printf("%d\n", a&b);
   printf("%d\n", a|b);
   printf("%d\n", a^b);
   printf("%d\n", a^b);
   printf("%d\n", a+=3);
   printf("%d\n", a-=8);
   printf("%d\n", a/=2);
   printf("%d\n", a*=4);
   printf("%d\n", a=4);
   printf("%d\n", a>b);
   printf("%d\n", a==b);*/

  /* int x= 4>=4? 67:76;
   char ch= 5==7? 'B':'G';
   printf("%d \n", x);
   printf("%c", ch);*/

   /*int a=45;
   printf("%d \n", a>>2);
   printf("%d", a<<2);*/

   /*double x;
   x= 300;
   printf("% 0.14lf", x);*/

   
   /*int a=2; int b=4; double c;int format;
   c= sqrt(a*a+b*b);
   format =c;
   printf("%*lf \n", format,c);*/

   int x=12;
   int y=9;
   int z=14;
   double a=3;
   printf("%d\n", y,z);

   int g=x/5+z/a;
   printf("%d\n", g);

   a=(z+x)/y;
   printf("%lf", a);

    return 0;
}
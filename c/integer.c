#include<stdio.h>
//computer left to right jo divide or multiply mein se pehle aa jata hai usse kar deta hai...
int main ()
{
  int a=17;
  int b=2;
  printf("%d \n", a+b);
  printf("%d\n", a-b);
  printf("%d\n", a/b);
  printf("%d\n", a*b);
  printf("%d\n", a%b);
  printf("%d\n", a-a/b*b);
  printf("%d\n", a-a*b/b);

  //hum yeh bhi kar skte hain
  
  int c=a/b;
  printf("%d", a-c*b);

    return 0;
}
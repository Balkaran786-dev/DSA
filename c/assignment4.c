#include<stdio.h>

int main(){
 int a=10;
        int *p=&a;
        printf("%d %p\n", *p,p);
        p+=3;
        printf("%d %p\n", *p,p);
        p-=2; 
        printf("%d %p\n", *p,p);
        p++;
        printf("%d %p\n", *p,p);
        p--;
        printf("%d %p\n", *p,p);

  return 0;
}

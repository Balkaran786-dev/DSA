#include<stdio.h>
typedef int* pointer;
typedef float realnumber;
int main(){
    int x=5,y=8;
    pointer a=&x,b=&y;
    printf("%p %p\n",a,b);

    realnumber p=8.9;
    printf("%f",p);
}


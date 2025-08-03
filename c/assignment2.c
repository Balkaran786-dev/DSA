 #include<stdio.h>

int main()
{   
    int a=7;
    int b=3;
    printf("%d %d %d %d \n", a++,b--,++a,--b);
    int c=a++;
    int d=--b;
    printf("%d %d %d %d",a,b,c,d);
    
    return 0;
}

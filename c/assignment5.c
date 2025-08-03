#include<stdio.h>

int main(){
  /*  int num;
    printf("Enter a number:");
    scanf("%d", &num);
    int power=1,binary=0;
    int a;
    while(num>=1){
        a=num%2;
        binary+=a*power;
        power*=10;
        num=num/2;
    }
    printf("%d", binary);

    int num;
    int d;
    printf("Enter a number:");
    scanf("%d", &num);
    d=num;
    int sum=0;
    int a;
    while(num>0){
        a=num%10;
        sum+=a*a*a;
        num=num/10;
    }
    if(d==sum){
        printf("IT IS AN ARMSTRONG NUMBER");
    }
    else{
        printf("IT IS NOT AN ARMSTRONG NUMBER");
    }




       int n; //rows
       int m;  //columns
        printf("Enter n:");
        scanf("%d", &n);
        printf("Enter m:");
        scanf("%d", &m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i;j++){
                printf(" ");
            }
            for(int j=1;j<=2*i-1;j++){
                printf("*");
            }
            printf("\n");
        }*/

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
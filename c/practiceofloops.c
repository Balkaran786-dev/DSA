#include<stdio.h>

int main(){
  /*  int product;
    for(int i=2;i<=4;i++){
        for(int j=1;j<=10;j++){
            product=i*j;
            printf(" %d ",product);
        }
        printf("\n");
    }
          //TO PRINT EVEN NUMBER FROM 1 TO 100
    for(int i=2;i<=100;i+=2){
        printf("%d ", i);
    }

          //OR
    for(int i=1;i<=100;i++){
        if(i%2==0){
            printf("%d ", i);
        }
    }
           //FACTORIAL OF A NUMBER
    int n;
    printf("Enter a number n:");
    scanf("%d",&n);
    int factorial=1;
    for(int i=n;i>=1;i--){
        factorial*=i;
    }
    printf("The factorial of the given number is: %d",factorial);*/

    int n;
    printf("Enter a number n:");
    scanf("%d", &n);
    bool isPrime = true;
    for(int i=2;i<n;i++){
        if(n%i==0){
            isPrime = false;
            break;
        }
    }
    if (isPrime){
        printf("IT IS A PRIME NUMBER");
    }
    else{
        printf("IT IS NOT A PRIME NUMBER");
    }
    return 0;
}
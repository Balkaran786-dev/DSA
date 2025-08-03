#include<stdio.h>

int main(){

  /*  int n;
    printf("Enter the number n:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            printf("%d",j);
        }
        for(int j=1;j<=i-1;j++){
            printf("%d",j);
        }
        printf("\n");
    }

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            printf(" ");
        }
        for(int j=1;j<=2*i-1;j++){
            printf("*");
        }
        printf("\n");
    }

    
   int n,m;
   scanf("%d %d",&n,&m);
   for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if((i+j)%2==0){
            printf("1");
        }
        else{
            printf("2");
        }
    }
    printf("\n");
   }

   int n,m;
   scanf("%d %d", &n,&m);
   for(int i=1;i<=n;i++){
    for(int j=1;j<=n-i;j++){
        printf(" ");
    }
    for(int j=1;j<=i;j++){
        printf("%d", j);
    }
    for(int j=i-1;j>0;j--){
        printf("%d",j);
    }
    printf("\n");
   }*/

   int n,m;
   scanf("%d %d",&n,&m);
   for(int i=1;i<=n;i++){
    for(int j=1;j<=n-i;j++){
        printf(" ");
    }
    for(int j=i;j<=2*i-1;j++){
        if(i==1||i==n||j==i||j==){
            printf("%d",i);
        }
        else{
            printf(" ");
        }
    }
    printf("\n");
   }

    return 0;

}
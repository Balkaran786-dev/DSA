#include<stdio.h>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr1[n][m];
    int sum1=0;
    int p,q;
    scanf("%d %d",&p,&q);
    int arr2[p][q];
    int sum2=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum1+=arr1[i][j];
        }
    }
      printf("%d\n",sum1);
      
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            sum2+=arr2[i][j];
        }
    }
    printf("%d\n",sum2);
}
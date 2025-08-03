#include<stdio.h>
int main(){
    for(int i=0;i<=3;i++){
        for(int j=1;j<=4;j++){
            if(j<=4-i){
                printf("%d",j);
            }
            else{
                printf(" ");
            }
        }
        for(int k=3;k>=1;k--){
            if(k<=4-i){
                printf("%d",k);
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
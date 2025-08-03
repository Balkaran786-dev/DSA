#include<stdio.h>
#include<math.h>
int main(){
    int num;
    scanf("%d",&num);
    int q=num;
    int count=0;
    while(q>0){
        count+=1;
        q/=10;
    }
    q=num;
    int result=0;
    int a;
    while(q>0){
        a=q%10;
        result+=pow(a,count);
        q/=10;
    }
    if(result==num){
        printf("it is a armstrong number");
    }
    else{
       printf("it is not a armstrong number");
    }
    return 0;
}
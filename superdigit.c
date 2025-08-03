#include<stdio.h>
int main(){
    int num;
    printf("Enter the number:");
    scanf("%d",&num);
    int superdigit;
    while(num%10!=num){
        int lastdigit=0;
        int sum=0;
        while(num!=0){
            lastdigit=num%10;
            sum+=lastdigit;
            num/=10;
        }
        num=sum;
    }
    superdigit=num;
    printf("The superdigit of the the given number is:%d",superdigit);
}
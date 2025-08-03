#include<stdio.h>
int main(){
    int marks1,marks2,marks3;
    scanf("%d %d %d",&marks1 ,&marks2 ,&marks3);

    int sum=marks1+marks2+marks3;
    float average=sum/3.0;
    
    printf("%d %f",sum,average);
}
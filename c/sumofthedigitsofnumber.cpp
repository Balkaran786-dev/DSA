#include<iostream>
using namespace std;
int main(){
    int i;
    scanf("%d",&i);
    int sum=0;
    while(i>0){
        sum+=i%10;
        i=i/10;
    }
    printf("%d",sum);
}
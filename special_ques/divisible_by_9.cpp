#include<iostream>  //check if a number is divisible by 9 and return the smallest positive 
                    //number that can be added to the number to make it completely divisible by 
                    //9
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n>9 || n<0){
         int a=n;
         int s=0;
         while(a!=0){
            int b=a%10;
            s+=b;
            a/=10;
         }
         n=s;
    }
    cout<<n-9;

}
#include<iostream>
using namespace std;
int main (){
    int n;    //number of digits in a given number

    cout<<"Enter a number";
    cin>>n;
    int digits=0;
    while(n>0){
        n/=10;
        digits+=1;
    }
    cout<<digits<<endl;


    int num;
    cout<<"Enter the number: ";
    cin>>num;
    int sum=0;
    while(num>0){
        sum+=num%10;
        num/=10;
    }
    cout<<sum<<endl;


    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            sum-=i;
        }
        else{
            sum+=i;
        }
    }
    cout<<sum<<endl;


 int n;
 cin>>n;             // factorial of first n natural numbers
 for(int i=1;i<=n;i++){
   int factorial=1;
   for(int j=i;j>=1;j--){
      factorial*=j;
   }
   cout<<"FACTORIAL OF"<<i<<":"<<factorial<<endl;
 }


    int a,b;
    cin>>a>>b;
    int product=1;          //a raise to power b.
    for(int i=1;i<=b;i++){
        product*=a;
    }
    cout<<product;
    return 0;
    
}
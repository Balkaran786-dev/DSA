#include<iostream>
using namespace std;

int add(int num1,int num2){
   int sum=num1+num2;
    return sum;
}
int add(int x,int y,int z){
    int sum=x+y+z;
    return sum;
}
float add(float num1,float num2){
    float sum=num1+num2;
    return sum;
}
void welcome(){
    cout<<"YOUR CODING JOURNEY HAS STARTED";
    return;   // you can skip this line in void returntype..
}

int main (){
    int a=23;
    int b=43;
    cout<<add(a,b)<<endl;
    cout<<add(a,b,21)<<endl;
    float x=3.14;
    float y=3.11;
    cout<<add(x,y)<<endl;
    welcome();       //since it is a void type so we cant store it..
}
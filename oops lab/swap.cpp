#include<iostream>
using namespace std;
struct number{
 int a;
 int b;
};
void swap1(int a,int b){ //call by value
     int temp=a;
     a=b;
     b=temp;
}
void swap2(int &a,int &b){ //call by reference
     int temp=a;
     a=b;
     b=temp;
}
void swap3(int *a,int *b){ //call by address
     int temp=*a;
     *a=*b;
     *b=temp;
}
int main(){
    int num1,num2;
    cin>>num1>>num2;

    swap1(num1,num2);

    cout<<"Value of num1 is: "<<num1<<endl;
    cout<<"Value of num2 is: "<<num2<<endl;

    swap2(num1,num2);
    cout<<"Value of num1 is: "<<num1<<endl;
    cout<<"Value of num2 is: "<<num2<<endl;

    int n=9,m=10;
    swap3(&n,&m);
    cout<<"Value of num1 is: "<<n<<endl;
    cout<<"Value of num2 is: "<<m<<endl;
    return 0;
}
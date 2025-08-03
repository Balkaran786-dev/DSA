#include<iostream>
using namespace std;

int main(){
    
    int a,b;
    cout<<"The value of a :";
    cin>>a;
    cout<<"The value of b :";
    cin>>b;
    int c;
    c=b;
    b=a;
    a=c;
    cout<<"a:"<<a<<endl;
    cout<<"b:"<<b<<endl;

      // OR

      int x,y;
      cout<<"The value of x:";
      cin>>x;
      cout<<"The value of y:";
      cin>>y;
      x=x-y;
      y=x+y;
      x=y-x;
      cout<<"final value of x :"<<x<<endl;
      cout<<"final value of y :"<<y<<endl;

      //OR
      
      int p,q;
      cout<<"The value of p:";
      cin>>p;
      cout<<"The value of q:";
      cin>>q;
      p=p^q;
      q=p^q;
      p=p^q;
      cout<<"final value of p :"<<p<<endl;
      cout<<"final value of q :"<<q<<endl;

    return 0;
}
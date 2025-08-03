#include<bits/stdc++.h>
using namespace std;
class A{
public:
    int x;
    void f(int b){
        cout<<"The value passed is: "<<b;
    }
};
int main(){
   int A::*ptiptr=&A::x;   //pointer to data member
   void (A::*ptfptr)(int)=&A::f; //pointer to member function
   
   //initialised the object without using pointer
   A obj;
   obj.*ptiptr=70;
   cout<<obj.x<<endl;

   (obj.*ptfptr)(89);


   //initialised the object with using pointer
    A *ptr=new A;
   ptr->*ptiptr=70;
   cout<<ptr->*ptiptr<<endl;

   (ptr->*ptfptr)(89);
}
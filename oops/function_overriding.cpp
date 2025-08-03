#include<iostream>
using namespace std;
class Parent{
public: 
    virtual void print(){     //virtual keyword is used for function overridding.hence child class gets print in case of print function
        cout<<"Parent class"<<endl;
     }
      void  show(){
        cout<<"Parent class"<<endl;
     }
};
class Child: public Parent{
public: 
     void print(){
        cout<<"Child class"<<endl;
     }
     void show(){
        cout<<"Child class"<<endl;
     }
};
int main(){
   Parent *p;
   Child c;
   p=&c;       //since we assigned the c object to p,so p needs to print 
               //the function present in child class.but it only happens,if in case 
               //we have used the virtual operator.
   p->print();
   p->show();
    return 0;
}



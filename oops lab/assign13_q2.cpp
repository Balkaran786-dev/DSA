#include<iostream>
using namespace std;
class Shape{ 
public:
    float a;
    float b;

    void get_data(float a,float b){
        this->a=a;
        this->b=b;
    }

    virtual void area(){};
};

class Rectangle:public Shape{
public:
     void area(){
        cout<<"Area of Rectangle:- "<<endl;
        cout<<a*b<<" sq units."<<endl;
     }
};
class Triangle:public Shape{
public:
     void area(){
        cout<<"Area of Triangle:- "<<endl;
        cout<<(a*b)/2<<" sq units."<<endl;
     }
};
int main(){
    Rectangle r;
    float length,breadth;
    cout<<"Give the values of length and breadth for rectangle:-"<<endl;
    cin>>length>>breadth;

    Triangle t;
    float base,height;
    cout<<"Give the values of base and height for triangle:-"<<endl;
    cin>>base>>height;
    
    Shape* base_ptr;
    base_ptr=&r;
    base_ptr->get_data(length,breadth);
    base_ptr->area();

    base_ptr=&t;
    base_ptr->get_data(base,height);
    base_ptr->area();
}
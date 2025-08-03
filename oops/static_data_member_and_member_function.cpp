#include<bits/stdc++.h>
using namespace std;
class Employee{
       int id;
     //this is only associated with the class,not with each and every object,hence also known as class variable.
   public:
   
     static int count;
     void set_data(){
        cout<<"Give the id of employee: "<<endl;
        count++;
        cin>>id;
     }
     void get_data(){
        cout<<"The id of employee is: "<<id<<" and the employee no. is: "<<count<<endl;
     }
     static void get_count(){
      // cout<<id;   //it gives error;
      cout<<"The value of count is:- "<<count<<endl;
     }
};
int Employee::count;  //default value is 0,we can initialise the static member with some other value here only,we can't initialise it inside class.
int main(){
    Employee harry,rohan,seghal;
    harry.set_data();
    harry.get_data();
    Employee::get_count();

    rohan.set_data();
    rohan.get_data();
    Employee::get_count();

    seghal.set_data();
    seghal.get_data();
    Employee::get_count();

    //cout<<Employee::id<<endl; //two wrong things,first id is private and second even if you make it public,you can't access it through class name,because it is not static,
    //you can access only static data memebers or member function by class name::  
    cout<<Employee::get_data<<endl;  //it gives 1
    cout<<Employee::count<<endl;//in this way,you can access the static variable
    cout<<harry.count<<endl; 
    cout<<seghal.count;
    return 0;
}

//static variable sirf ek hota hai and is shared by all objects.
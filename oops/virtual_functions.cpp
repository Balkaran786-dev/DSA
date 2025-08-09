// A member function in the base class which is declared using virtual keyword is called virtual functions.
// They can be redefined in the derived class. 

//virtuality will be inherited..


#include<iostream>
using namespace std;

class BaseClass{
    public:
        BaseClass(){
            cout<<"j";
        }
        int var_base=1;
        virtual void display(){
            cout<<"1 Dispalying Base class variable var_base "<<var_base<<endl;
        }
};

class DerivedClass : public BaseClass{
    public:
            int var_derived=2;
            void display(){
                cout<<"2 Dispalying Base class variable var_base "<<var_base<<endl;
                cout<<"2 Dispalying Derived class variable var_derived "<<var_derived<<endl;
            }
};
int main(){
    BaseClass * base_class_pointer;
    BaseClass obj_base;
    DerivedClass obj_derived;

    base_class_pointer = &obj_derived;
    base_class_pointer->display();  //it will call the display function of derived class
    
    return 0;
}

/* we have used the “virtual” keyword with the “display” function of the base class
 to make is virtual function so when the display function is called by using the 
 base class pointer the display function of the derived class will run*/
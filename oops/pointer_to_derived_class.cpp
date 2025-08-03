#include <iostream>
using namespace std;
class Base {
public:
    void print() {
        cout << "\n PRINT - BASE CLASS";
    }
};

class Derived : public Base {
public:
    void print() {
        cout << "\n PRINT - DERIVED CLASS";
    }
};

int main() {
    Base B, *bptr;
    Derived D, *dptr;

    bptr = &B;     // Base class pointer points to base class object
    bptr->print(); // Output: PRINT - BASE CLASS

    bptr = &D;     // Base class pointer points to derived class object
    bptr->print(); // Output: PRINT - BASE CLASS (object slicing)

    dptr = &D;     // Derived class pointer points to derived class object
    dptr->print(); // Output: PRINT - DERIVED CLASS

    return 0;
}



//from code with harry..
#include<iostream>
using namespace std;
class BaseClass{
    public:
        int var_base;
        void display(){
            cout<<"Dispalying Base class variable var_base "<<var_base<<endl;
        }
};

class DerivedClass : public BaseClass{
    public:
            int var_derived;
            void display(){
                cout<<"Dispalying Base class variable var_base "<<var_base<<endl;
                cout<<"Dispalying Derived class variable var_derived "<<var_derived<<endl;
            }
};
int main(){

    BaseClass * base_class_pointer;
    BaseClass obj_base;
    DerivedClass obj_derived;
    base_class_pointer = &obj_derived; // Pointing base class pointer to derived class

    base_class_pointer->var_base = 34;
    base_class_pointer->var_derived= 134; // we can not set derived class data members through base class pointer otherwise it Will throw an error
    base_class_pointer->display();

    base_class_pointer->var_base = 3400; 
    base_class_pointer->display();

    DerivedClass * derived_class_pointer;
    derived_class_pointer = &obj_derived;
    derived_class_pointer->var_base = 9448;// agr yeh na bhi likhte, toh a=hamara var_base 3400 print hota,voh kyu? explained nicche
    derived_class_pointer->var_derived = 98;
    derived_class_pointer->display();

    return 0;
}
//because base_class_pointer points to obj_derived,iss pointer ke through hummne ess object ke var_base ko
//already set krdiya 3400 in line 64.that's why.


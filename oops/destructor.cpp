/*whenever we have formed an object inside main function,its destructor will be called after
the main function,but if it is formed in some block,its destructor is called after the block ends. */


#include<iostream>
using namespace std;
class Rectangle{
public:
     int l;
     int b;

     Rectangle(){  //default constructor-> no arguement are passed.
        l=0;
        b=0;
     }

     Rectangle(int x,int y){ //parametrised constructor-> arguement are passed.
         l=x;
         b=y;
     }

     Rectangle(Rectangle &r){ //copy constructor-> initialise an object by another existing object.
         l=r.l;
         b=r.b;
     }

     ~Rectangle(){
        cout<<"Destructor is called"<<endl;
     }
};
int main(){
    Rectangle* r1=new Rectangle();
    cout<<r1->l<<" "<<r1->b<<endl;
    delete r1; //it can only be used for pointer variable.

    Rectangle r2(4,5);
    cout<<r2.l<<" "<<r2.b<<endl;

    Rectangle r3 = r2;
    cout<<r3.l<<" "<<r3.b<<endl;  //eske baad means main function ke baad fir dono r2 and r3 ke destructor call honge.but 
                                  //pointer variable vala destructor uski defining ke baad hi call ho jayega.
    return 0;
}


//when a destructor is called private:

#include <iostream>

class MyClass {
private:
    ~MyClass() {
        std::cout << "Private destructor called\n";
    }

public:
    static void destroy(MyClass* obj) {
        delete obj; // Calls the private destructor
    }
};

int main() {
    MyClass* obj = new MyClass();
    MyClass::destroy(obj); // Private destructor is invoked
    return 0;
}

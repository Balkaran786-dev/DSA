// #include<iostream>
// using namespace std;   //single inheritance
// class Parent{
// public:   
//     Parent(){
//         cout<<"Parent class"<<endl;
//     }
// };

// class Child: public Parent{
// public:  
//     Child(){
//         cout<<"Child class"<<endl; //firsly,the constructor of parent class
//                                    // will be called, then of child class.
//     }
// };

// int main(){
//     Child c; 
//     return 0;
// }

//if all these three classes have a function with same name,
//if we create the object of grandchild class and call that function through that object
//in main,it will call the function defined in grandchild class.
//because
//When you create an object of Grandchild and call g.show(), 
//the compiler looks for the show() method in Grandchild first. 
//Since Grandchild has its own implementation of show(), that version is called.
//if granchild,doesn't have that function,it will check for the function in child class and 
//and call it...if we really want to call the function of top(parent),call it explicitly as object.parent::func();

//explanation::---

//Method Resolution: When you create an object of Grandchild and call g.show(), 
//                  the compiler looks for the show() method in Grandchild first. 
//                   Since Grandchild has its own implementation of show(), that version is called.
//Function Overriding: The show() method in Grandchild overrides the show() methods in both Child and Parent. 
//                      This means Grandchild::show() hides Child::show() and Parent::show().


// #include<iostream>
// using namespace std;  //multi-level inheritance
// class Parent{
// public:   
//     Parent(){
//         cout<<"Parent class"<<endl;
//     }
// };

// class Child: public Parent{
// public:  
//     Child(){
//         cout<<"Child class"<<endl;
//     } 
// };

// class Grandchild: public Child{
// public:
//     Grandchild(){
//         cout<<"Grandchild class"<<endl;
//     }
// };

// int main(){
//     Grandchild gc; 
//     return 0;
// }

// #include<iostream>
// using namespace std;   //multiple inheritance

// class Parent1{
// public: 
//     int c;  
//     Parent1(){
//         c=9;
//         cout<<"Parent1 class"<<endl;
//     }

// };

// class Parent2{
// public:   
//     Parent2(){
//         cout<<"Parent2 class"<<endl;
//     }
// };

// class Child: public Parent1,public Parent2{
// public: 
//     Child(){
//         cout<<"Child class"<<endl; 
//     }
// };

// int main(){
//     Child b;
//     cout<<b.c<<endl;
//     return 0;
// }



// #include<iostream>
// using namespace std;   //hierarchical inheritance
// class Parent{
// public:   
//     Parent(){
//         cout<<"Parent class"<<endl;
//     }
// };

// class Child1: public Parent{
// public:  
//     Child1(){
//         cout<<"Child1 class"<<endl; 
//     }
// };

// class Child2: public Parent{
// public:  
//     Child2(){
//         cout<<"Child2 class"<<endl; 
//     }
// };
// int main(){
//     Child1 c1;
//     Child2 c2; 
//     return 0;
// }


#include <iostream>

using namespace std;

class Parent {};
class Child : public Parent {};

int main() {
    Parent *p = new Child;
    Child *c = new Parent;
}

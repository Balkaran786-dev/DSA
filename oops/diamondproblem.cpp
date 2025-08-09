// #include<iostream>
// using namespace std;

// class parent{
// public:
//     parent(){
//     cout<<"parent class"<<endl;
//     }
// };

// class child1: public parent{
// public:
//     child1(){
//         cout<<"child1 class"<<endl;
//     }
// };

// class child2: public parent{
// public:
//     child2(){
//         cout<<"child2 class"<<endl;
//     }
// };

// class grandchild: public child1,public child2{   //if child2 is declared as virtual,then its constructor will be called before child1
// public:
//     grandchild(){
//         cout<<"grandchild class"<<endl;
//     }
// };

// int main(){
//     grandchild gc;
//     return 0;
// }

//solution to diamond problem:virtual inheritance
/*The diamond problem is solved by declaring the common base class 
(A) as a virtual base class when B and C inherit from A. This ensures 
that only one shared instance of A is created, regardless of how
many times it is indirectly inherited through B and C.*/

//how it works:
//When B and C are declared to inherit A virtually, the compiler ensures that D does not create multiple instances of A.
//The most derived class (D) manages the construction and destruction of the single instance of A, preventing redundant copies.

#include<iostream>
using namespace std;

class parent{
public:
    parent(){
    cout<<"parent class"<<endl;
    }
};

class child1: virtual public parent{
public:
    child1(){
        cout<<"child1 class"<<endl;
    }
};

class child2: virtual public parent{
public:
    child2(){
        cout<<"child2 class"<<endl;
    }
};

class grandchild: public child1, public child2{
public:
    grandchild(){
        cout<<"grandchild class"<<endl;
    }
};

int main(){
    grandchild gc;
    return 0;
}
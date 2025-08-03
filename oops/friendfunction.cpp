// #include<iostream>
// using namespace std;
// class A{
//     int x;

// public:
//     A(int y){
//         x=y;
//     }
//     friend void print(A &obj);  //friend function is non member function which can access private
//                                 //member of the class.
// };
// void print(A &obj){
//     cout<<obj.x<<endl;
// }
// int main(){
//     A obj(5);
//     print(obj);
//     return 0;
// }

// #include<iostream>
// #include<math.h>
// using namespace std;
// class some{
//     int x;
// public:
//     some(int a){
//         x=a;
//     }

//     friend int square(some &obj);
// };
// int square(some &obj){
//     return pow(obj.x,2);
// }
// int main(){
//    some A(6);
//    cout<<square(A);
// }


//friend function is non member function which can access private members of the class.
//it is used when we need to interact with the private data of more than one classes at a single time.
//it can be declared either in the private or public section of the class,its meaning doesn't change.
//friend function doesn't fall in the scope of any class.hence its functionality is not limited any class.
//it is not called by the object of any class.it is called as a normal function.
//we can write friend returntype function_name or returntype friend function_name
//friend function cannot explicitly call the private data.you need to call it through the object of that class.



//friend of two classes
#include<bits/stdc++.h>
using namespace std;
class bcd;
class abc{
    int x;
    public:

    abc(int x){
        this->x=x;
    }

    void friend max(abc,bcd);
};
class bcd{
    int y;
    public:
    bcd(int y){
        this->y=y;
    }

    void friend max(abc,bcd);
};
void max(abc h,bcd g){
    if(h.x>=g.y){
        cout<<"The greater value is:"<<h.x;
    }
    else{
        cout<<"The greater value is:"<<g.y;
    }
}
int main(){
    abc h(89);
    bcd g(90);
    max(h,g);
    return 0;
}
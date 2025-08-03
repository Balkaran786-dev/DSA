// #include<iostream>  //here get data and show data are member function of A and friend function of B.
//                     //hence it can be called by the class A object using dot operator.
//                     //hence through this,we can access the private members of B class.
//                 //In this way, the member function of one class(who is also the friend function of another class)
//                 //can access the private data members of the another class.
// using namespace std;
// class B;
// class A{
//    int x;
//    public:

//    void get_data(B&);  //eski definition baad mein hi denge,kyunki abhi complier ko nhi pta chlega
//                       //ki class B mein y data memeber hai ke nhi.
//    void show_data(B&);
// };
// class B{
//    int y;          
//    public:

//    friend void A::get_data(B&);  //this function can nw access private data members of calss B.
//    friend void A::show_data(B&);
// };
// void A::get_data(B & obj){ 
//     cout<<"The private data y of B is: ";
//     cin>>obj.y;
//     cout<<"The private data x of A is: ";
//     cin>>this->x;
// }
// void A::show_data(B &obj){
//     cout<<"The value of x is: "<<this->x<<endl;
//     cout<<"The value of y is: "<<obj.y<<endl;
//     cout<<"The sum of the two numbers is: "<<this->x+obj.y<<endl;
// }
// int main(){
//     A a;
//     B b;
//     a.get_data(b);
//     a.show_data(b);
//     return 0;
// }


// //here getdata and showdata are the friend function of both the classes.
// #include<iostream>  
// using namespace std;
// class B;
// class A{
//    int x;
//    public:

//    friend void get_data(A&,B&);
//    friend void show_data(A&,B&);
// };
// class B{
//    int y;
//    public:

//    friend void get_data(A&,B&);
//    friend void show_data(A&,B&);
// };
// void get_data(A & obj1,B & obj2){ 
//     cout<<"The private data y of B is: ";
//     cin>>obj2.y;
//     cout<<"The private data x of A is: ";
//     cin>>obj1.x;
// }
// void show_data(A &obj1,B &obj2){
//     cout<<"The value of x is: "<<obj1.x<<endl;
//     cout<<"The value of y is: "<<obj2.y<<endl;
//     cout<<"The sum of the two numbers is: "<<obj1.x+obj2.y<<endl;
// }
// int main(){
//     A a;
//     B b;
//     get_data(a,b);
//     show_data(a,b);
//     return 0;
// }


#include<iostream>  
using namespace std;
class complex;
class calculator{
    public:
    complex sum(complex,complex);
};
class complex{
   int a,b;
   public:
   void set_values(int a,int b){
      this->a=a;
      this->b=b;
   }
   void display(){
    cout<<this->a<<" "<<this->b<<endl;
   }
   friend complex calculator:: sum(complex c1,complex c2);
};
complex calculator::sum(complex c1,complex c2){
    complex c3;
    c3.set_values(c1.a+c2.a,c1.b+c2.b);
    return c3;
}
int main(){
    complex c1,c2,c3;
    
    c1.set_values(1,2);
    c2.set_values(3,4);
    c1.display();
    c2.display();
    calculator cal;
    c3=cal.sum(c1,c2);
    c3.display();
    return 0;
}

//if their are more than 1 member functions
//of class A that want to acess the private data of 
//class B,than make the whole class A as the friend class 
//of B.



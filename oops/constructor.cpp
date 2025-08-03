/*when a copy constructor is called but you have not made it,
it calls a default copy constructor*/


// #include<iostream>
// using namespace std;
// class Rectangle{
// public:
//      int l;
//      int b;

//      Rectangle(){  //default constructor-> no arguement are passed.
//         l=0;
//         b=0;
//      }

//      Rectangle(int x,int y=10){ //parametrised constructor-> arguement are passed.
//          l=x;
//          b=y;
//      }
     
//      Rectangle(int x){
//       l=x;
//      }
//      Rectangle(Rectangle &r){ //copy constructor-> initialise an object by another existing object.
//          l=r.l;
//          b=r.b;
//      }
// };  //we also have a default copy constructor.
    
// class proffesors{
// public:
//      string name;
//      int age;

//      proffesors(){
//         name="abc";
//         age=0;
//      }

//      proffesors(string n,int a){
//         name=n;
//         age=a;
//      }

//    //   proffesors(proffesors &r){
//    //      name=r.name;
//    //      age=r.age;
//    //   }
// };
// int main(){
//    //  Rectangle r1;
//    //  cout<<r1.l<<" "<<r1.b<<endl;

//     Rectangle r2;
//     cout<<r2.l<<" "<<r2.b<<endl;

//    //  Rectangle r3 = r2;
//    //  cout<<r3.l<<" "<<r3.b<<endl;

   //  proffesors a;
   //  cout<<a.name<<"-"<<a.age<<endl;

   //  proffesors b("random",3);
   //  cout<<b.name<<" "<<b.age<<endl;

   //  proffesors c(b);   //default copy constructor made by the complier itself
   //  cout<<c.name<<" "<<c.age<<endl;
//     return 0;
// }


// #include<iostream>
// using namespace std;
// class complex{
//    int a;
//    public:
//    complex();
//    void print(){
//       cout<<a;
//    }
// };
// complex::complex(){
//    this->a=10;
// }
// int main(){
//    complex c;
   
//    c.print();
// }


//if you have just defined a parametrised constructor,
//but you r not giving a single value during object initialisation
//it gives error.it won't call inbuilt default constructor.


//implementing a code to find dist between two point objects ,take friend function to
//calculate dist

// #include<bits/stdc++.h>
// using namespace std;
// class point{
//    int x,y;
//    public:
//    point(int x,int y){
//       this->x=x;
//       this->y=y;
//    }
//    friend int dist(point p1,point p2);
// };
// int dist(point p1,point p2){
//    return sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2));
// }
// int main(){
// //    point p1(1,0);
// //    point p2(70,0);
// //    cout<<dist(p1,p2);
// // }

 //calling your constructor indirectly by using a static member function:

// #include<iostream>
// using namespace std;
// class A{
//    int val;
//   A(){
//    val=10;
//   }
// //   ~A(){
// //    cout<<"destructor is called"<<endl;
// //   }
//   public:
//     static A initialise(){   //factory method
//       return A();
//     }
    
//     void show_data(){
//       cout<<"The value is: "<<val<<endl;
//     }
// };
// int main(){
//    A obj=A::initialise();  //also you can make a normal initilise function and call
//                            //it with the help of object.
//    obj.show_data();
  
//    return 0;
//}

//just find out how can you call your destructor if it is declared private
//example1

// C++ program to demonstrate an explicit call of destructor 
// #include <iostream> 
// using namespace std; 

// class Test { 
// public: 
// 	Test() { cout << "Constructor is executed\n"; } 
// 	~Test() { cout << "Destructor is executed\n"; } 
// 	void show() 
// 	{ 
// 		Test(); //yahan humara ek temp object bana hoga.jiska ek bar pehle constructor call ua fer uska hi destrctor
// 		this->Test::~Test();   //eska ek destructor calll hua
// 	} 
// }; 

// int main() 
// { 
// 	Test t;   //ek constructor yahan call hua
// 	t.show(); 
//    //aakhri mein jab t object destroy hua tabh bhi ek destructor call hua
// 	return 0; 
// }

//example 2

// C++ program to demonstrate an explicit call 
#include <iostream> 
using namespace std; 

class Test { 
public: 
	Test() { cout << "Constructor is executed\n"; } 
	~Test() { cout << "Destructor is executed\n"; } 
}; 

int main() 
{ 
	Test(); // Explicit call to constructor 
	Test t; // local object 
	t.~Test(); // Explicit call to destructor 
	return 0; 
}

// //example 3
// #include <iostream> 
// using namespace std; 

// class Test { 
// public: 
// 	Test() { cout << "Constructor is executed\n"; } 
// 	~Test() { cout << "Destructor is executed\n"; } 
// 	friend void fun(Test t); 
// }; 
// void fun(Test t) 
// { 
// 	Test(); 
// 	t.~Test(); 
// } 
// int main() 
// { 
// 	Test(); 
// 	Test t; 
// 	fun(t); 
// 	return 0; 
// }



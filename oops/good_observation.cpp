#include<iostream>
using namespace std;
class student{
public:
   static int a;
   int b;
   student(){
      b=10;
      a++;
   }
};
int student:: a;
int main(){
   // 1.
     student *s=new student[5];
     cout<<student::a;

   //2.
    student *s[5];
     cout<<student::a;
  
  // 3.
   student s1,s2;  //a=2
   new student();  //a=3
   cout<<(new student())->b<<endl; //a=4
   cout<<student::a;
}



#include <iostream>
#include <stdlib.h>
using namespace std;

class Sample {
    static int A;

public:
    Sample()
    {
        A++;
    }
    static void fun()
    {
        cout << A << endl;
    }
};
int Sample::A = 0;

int main()
{
    static void (*F_PTR)();

    Sample S1, S2;
    
    F_PTR = Sample::fun;  //it gives a pointer 
    F_PTR();

    return 0;
}


// //return by reference
// #include<iostream>
// using namespace std;
// class complex{
// public:
//    int real;
//    int img;

//    complex(int x,int y){
//       real=x;
//       img=y;
//    }
//    complex &compare(complex &c2);
// };
// int main(){
//    // complex c1(2,3);
//    // complex c2(2,4);

//    // complex c3=c1.compare(c2);
//    // cout<<c3.real<<"+j"<<c3.img;


//    complex c1(2,3);
//    complex c2(2,4);

//    (c1.compare(c2)).real=5;
//    cout<<c2.real<<"\f+j"<<c2.img;
//    return 0;
// }
// complex &complex:: compare(complex &c2){
//    if(real<c2.real) return c2;
//    else if(real==c2.real){
//       if(img<c2.img){
//          return c2;
//       }
//       else{
//          return *this;
//       }
//    }
//    else return *this;
// }
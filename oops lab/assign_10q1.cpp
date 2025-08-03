// // using member function.
// #include<iostream>
// using namespace std;
// class trial{ 
//     int a; 
// public: 
//     void setdata(int x){ 
//         a=x; 
//     } 
//     void showdata(){
//         cout<<a<<endl;
//     } 
//     trial operator++(){ 
//         trial t3; 
//         t3.a=++this->a; 
//         return t3; 
//     }
//     trial operator++(int){
//         trial t3;
//         t3.a=this->a++;
//         return t3;
//     }
// };
// int main(){
//      cout<<"Using member function"<<endl;
//      trial t1,t2; 
//      t1.setdata(6); 
//      //pre increment
//      t2=++t1; 
//      t1.showdata(); 
//      t2.showdata(); 
//      //post increment
//      trial t3;
//      t3=t1++;
//      t1.showdata(); 
//      t3.showdata();

//      return 0;
// }


//using friend function
#include<iostream>
using namespace std;
class trial{ 
    int a; 
public: 
    void setdata(int x){ 
        a=x; 
    } 
    void showdata(){
        cout<<a<<endl;
    } 
    friend trial operator++(trial&);
    friend trial operator++(trial&,int);
};

trial operator++(trial &t1){
    trial t3;
    t3.a=++t1.a;
    return t3;
}
trial operator++(trial& t1,int){
    trial t3;
    t3.a=t1.a++;
    return t3;
}
int main(){
     cout<<"Using friend function"<<endl;
     trial t1,t2; 
     t1.setdata(6);
     //preincrement 
     t2=++t1; 
     t1.showdata(); 
     t2.showdata(); 
     //using post incremet
     trial t3;
     t3=t1++;
     t1.showdata(); 
     t3.showdata();
     return 0;
}



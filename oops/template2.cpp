#include<iostream>
using namespace std;
//template<class t1,class t2,...class tn>
template<class T1,class T2> //we can have any number of parameters with comma separated values
class myClass{
public:
   T1 data1;
   T2 data2;

   myClass(T1 x,T2 y){
    data1=x;
    data2=y;
   }
};
int main(){
    myClass<int,float> obj(5,67.9);
    cout<<obj.data1<<" "<<obj.data2;
}

// //default arguements
// #include<iostream>
// using namespace std;
// //template<class t1,class t2,...class tn>
// template<class T1=int,class T2=char> //we can have any number of parameters with comma separated values
// class myClass{
// public:
//    T1 data1;
//    T2 data2;

//    myClass(T1 x,T2 y){
//     data1=x;
//     data2=y;
//    }
// };
// int main(){
//     myClass<> obj(5,67.9);
//     cout<<obj.data1<<" "<<obj.data2<<endl;

//     myClass<float> obj1(5.67,'u'); //same cases of default arguement in functions
//     cout<<obj1.data1<<" "<<obj1.data2;
// }
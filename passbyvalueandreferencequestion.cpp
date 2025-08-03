#include<iostream>
using namespace std;
// void decrease(int n1,int n2){
//   n1--;
//   n2=n2-2;
//   cout<<n1<<":"<<n2<<endl;  //n1 and n2 are formal parameters
// }
// int main(){     
//     int p=26; 
//     int q=13;
//     decrease(p,q); //p and q are formal parameters
//     cout<<p<<":"<<q;
// }   /*due to pass by value, copies are created of n1 and n2 in which values 
//     values of p and q are copied respectively..so the operation applied on
//     n1 and n2 will not be applicable on p and q..*/




// void maketwice(int p){ // here p is formal parameter
//     p=p*2;
//     cout<<p<<endl;
// }
// int main(){
//     int p=24; 
//     maketwice(p);  // here p is actual parameter
//     cout<<p;
// }  /*due to pass by value,value of actual paramter p will get cpied
//     to formal parameter p,hence operation applied on formal parameter p will 
//     not be applicable on actual parameter..*/




void temp(int p){  // actual parmeter value i.e 890 gets copied to it..
    int q=p; //q=890
    q=q-100;  // q=790
}
int main(){
    int p=890;
    temp(p);
    cout<<q;  // since q was not in the scope of main function,it will throw an error
}
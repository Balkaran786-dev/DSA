#include<iostream>
using namespace std;
class Empty_class{};
class stu{
public:
  int roll;

    stu(){
    cout<<"Hello";
  }
};
int main(){
    // Empty_class obj1;
    // cout<<"The size of the object of an empty class is:- "<<sizeof(obj1)<<endl;
    
    // Empty_class obj2;

    // Empty_class *ptr1=&obj1;
    // Empty_class *ptr2=&obj2;
    // cout<<"The address of 1st object is: "<<ptr1<<" and the size of the obj1 is: "<<sizeof(*ptr1)<<endl;
    // cout<<"The address of 2nd object is: "<<ptr2<<" and the size of the obj2 is: "<<sizeof(*ptr2)<<endl;
    stu s;
    s.stu();
}
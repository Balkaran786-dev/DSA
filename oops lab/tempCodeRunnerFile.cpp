#include<iostream>
using namespace std;
class student{
public:
     int age;  //public data member

     student(int age){   //constructor
        this->age=age;
     }
};

float average(student &s1,student &s2){  
    float avg=(s1.age+s2.age)/2;
    return avg;
}
int main(){
    student Balkaran(79);
    student lucy(56);

    cout<<"The average of two students is: "<<average(Balkaran,lucy);
    return 0;
}
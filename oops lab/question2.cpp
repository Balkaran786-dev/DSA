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
    int age1,age2;
    cout<<"Enter the ages of both the persons:- "<<endl;
    cin>>age1>>age2;
    student Balkaran(age1);
    student lucy(age2);

    cout<<"The average of two students is: "<<average(Balkaran,lucy);
    return 0;
}
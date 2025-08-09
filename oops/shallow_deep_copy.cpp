// //shallow copy
// #include<iostream>
// using namespace std;
// class student{
// public:
//     string name;
//     double* cgpaptr;
//     student(string name,double cgpa){
//         this->name=name;
//         cgpaptr=new double;
//         *cgpaptr=cgpa;
//     }
//     void get_info(){
//         cout<<"The name of student is: "<<this->name<<endl;
//         cout<<"The cgpa of student is: "<<*(this->cgpaptr)<<endl;
//     }
//     student(student &s){
//         this->name=s.name;
//         this->cgpaptr=s.cgpaptr;  //basically stores the same memory location to the curr object
//     }

// };

// int main(){
//     student obj1("harry",8.9);
//     obj1.get_info();
//     student obj2(obj1);
//     *(obj2.cgpaptr)=9.2;
//     obj1.get_info();  //iski cgpa bhi change ho rhi hai
//     return 0;
// }

//to avoid above problem,we do deep copy given below;

//deep copy
#include<iostream>
using namespace std;
class student{
public:
    string name;
    double* cgpaptr;
    student(string name,double cgpa){
        this->name=name;
        cgpaptr=new double;
        *cgpaptr=cgpa;
    }
    void get_info(){
        cout<<"The name of student is: "<<this->name<<endl;
        cout<<"The cgpa of student is: "<<*(this->cgpaptr)<<endl;
    }
    student(student &s){
        this->name=s.name;
        cgpaptr=new double;  //new memory allocate kardi
        *(this->cgpaptr)=*(s.cgpaptr);  //and uss new memory pe same value store krdi
    }    
};
class X{
  public:
    int x;
};
int main(){
    // student obj1("harry",8.9);
    // obj1.get_info();
    // student obj2(obj1);
    // *(obj2.cgpaptr)=9.2;
    // obj1.get_info();  

    X a={10};
    cout<<a.x;
    return 0;
}
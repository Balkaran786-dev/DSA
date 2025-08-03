#include<iostream>
#define ll long long int
using namespace std;
class student{
    string name;
    ll roll_no;
    int yr;
    
    public:
    void set_data();
    void get_data();
};

void student::set_data(){
    string name;
    cout<<"Enter name:- ";
    cin>>name;
    ll roll_no;
    cout<<"Enter roll no.:- ";
    cin>>roll_no;
    int yr;
    cout<<"Enter yr:- ";
    cin>>yr;
    this->name=name;
    this->roll_no=roll_no;
    this->yr=yr;
}
void student::get_data(){
    cout<<"The name of the student is: "<<this->name<<endl;
    cout<<"The roll no. of the student is: "<<this->roll_no<<endl;
    cout<<"The current yr of the student is: "<<this->yr<<endl;
    cout<<"******"<<endl;
}
int main(){
    int n;
    cout<<"The no. of students are:- ";
    cin>>n;
    student G1[n];
    for(int i=0;i<n;i++){
        G1[i].set_data();
    }

    for(int i=0;i<n;i++){
        G1[i].get_data();
    }
}
#include<iostream>
#include<vector>
using namespace std;
class student{

     int rollno;
     string name;
     vector<int> marks;
     int total_marks;

     public:
     void set_data(int rollno,string name,vector<int> &marks){
        this->rollno=rollno;
        this->name=name;
        for(int i=0;i<marks.size();i++){
            this->marks.push_back(marks[i]);
        }
     }
     int total(vector<int> &v){
            int sum=0;
            for(int i=0;i<3;i++){
                sum+=v[i];
            }
            return sum;
     }
     void display(){
        this->total_marks=total(marks);
        
        cout<<"The total marks of the student is: "<<total_marks;
        cout<<endl;
        cout<<rollno<<endl;
        cout<<name<<endl;
        for(int i=0;i<3;i++){
            cout<<marks[i]<<" ";
        }
     }
};
int main(){
    student s;
    vector<int> v={90,90,90};
    s.set_data(34,"Balkaran",v);
    s.display();
    return 0;
}
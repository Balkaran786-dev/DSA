#include<bits/stdc++.h>
using namespace std;
class worker{
   string name;
   int age;
public:
   static int no_of_workers;
   worker(){
      cout<<"worker class"<<endl;
      name="";
      age=0;
   }

   worker(string name,int age){
    this->name=name;
    this->age=age;
    no_of_workers++;
   }

   static void get_count(){
     cout<<"The no of workers are: "<<no_of_workers<<endl;
   }

};
int worker::no_of_workers;

class manager:  public worker{
  string name;
public:
  manager(){
    cout<<"manager class"<<endl;
    name="";
  }

};

class CEO: public manager{
    public:
      CEO(){
        cout<<"CEO class"<<endl;
      }
};
int main(){
    CEO obj;
}


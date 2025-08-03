#include<bits/stdc++.h>
using namespace std;
class worker{
   string name;
   int age;
public:
   static int no_of_workers;
   worker(){
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

class manager: public worker{
  string name;
public:
  manager(){
    name="";
  }

};
int main(){
    worker w1("A",23);
    worker w2("B",24);
    worker w3("C",25);
    worker w4("D",26);
 
    manager m;  
    m.get_count();

}
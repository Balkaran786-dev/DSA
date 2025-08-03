 /*encapsulation ensures that in oops the data in a class 
is only accessible from the methods and functions written 
in that particular class.*/

#include<iostream>
using namespace std;
class ABC{
    int x;  //here this is private to this class.Hence,we cannot operate on this data.
    
    public:  
    //we need to write set of functions with help of which we can manipulate on that data which is private. 
   void set(int n){  // this is written to give x a value;
    x=n;
   }
   int get(){     //this is written to access the value of x;
    return x;
   }

};

class aka{
  string x;
public:
   void set(string s){
    x=s;
   }
   string get(){
    return x;
   }
};
int main(){
    ABC obj1;
    obj1.set(3);
    cout<<obj1.get()<<endl;

    aka obj;
    obj.set("balkaran");
    cout<<obj.get()<<endl;
    return 0;
}

//from above two classes,we get to know that the variable x was only accessible from set and
//get function that were in that class.we could not directly access that varibale from main function
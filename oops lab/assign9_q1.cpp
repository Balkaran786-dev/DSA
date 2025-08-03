#include<iostream>
using namespace std;
class String{
      string s;
public:
       String(){
         this->s="";
       }

       String(string input){
        this->s=input;
       }

       String add(String &str){
           String New;
           New.s=this->s+str.s;
           return New;
       }

       void display(){
        cout<<"The string is: "<<this->s<<endl;
       }

};
int main(){
    String Check;
    String A("Balkaran");
    String B("Singh");
    String C=A.add(B);
    C.display();
    
    return 0;
}
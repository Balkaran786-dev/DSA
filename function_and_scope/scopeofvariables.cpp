#include<iostream>
using namespace std;
int apples=23;
void print(){
    cout<<apples;
}
int main(){
    int apples=15;
    cout<<apples<<endl;  //local variable precedence>global variable.
    cout<<::apples<<endl; //we use :: to print global variable.
    print();  // since this print() can use only global variable so it will print 23
    
    return 0;
}
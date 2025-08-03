#include<iostream>
using namespace std;  
class Parent{
public:
   int x;//accessible anywhere from the code.

protected:
   int y;//accessible only in own class,parent class& derived class.

private:
   int z;//only accessible in own class
};
int main(){
    Parent P1;
    P1.x;  
    return 0;
}
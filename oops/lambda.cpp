#include <iostream>
using namespace std;
class A{
public:
 int a;
 A(int a){
    a=a;
 }

};
int main() {
   A obj(8);
   cout<<obj.a;
} // Both staticVar and globalVar are destroyed after main, but globalVar might go first.

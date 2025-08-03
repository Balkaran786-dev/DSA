#include <iostream>
using namespace std;
class ClassB; 
class ClassA{
    private:
        int numA;
    public:
        ClassA(){
            numA=0;
        }
        // Friend class 
        friend class ClassB;
        void display() {
            cout << "ClassA: " << numA << endl;
        }
};
 
class ClassB{
    private:
        int numB;
    public:
        ClassB(){
            numB=0;
        }
 
        void setValue(ClassA& objA, int value) {
            objA.numA = value; 
        }
        void display(ClassA& objA) {
            cout << "ClassB: " << numB << endl;
            objA.display();
        }
};
int main() {
    ClassA objA;
    ClassB objB;
 
    objB.setValue(objA, 100);
    objB.display(objA);
 
    return 0;
}
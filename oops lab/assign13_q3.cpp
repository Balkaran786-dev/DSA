#include <iostream>
using namespace std;
class sample{
    public:
        virtual void example() = 0;
        virtual void show()=0;
};

class Ex1 : public sample{
    public:
        void example()
        {
            cout << "I'm sure that \n";
        }
         
};
class Ex2 : public Ex1{
    public:
        void show(){
            cout<<"I'm gonna make it\nand i'll show you all";
        }
};
int main()
{
    Ex2 obj;
    sample *ptr;
    ptr=&obj;
    ptr->example();
    ptr->show();
    
}

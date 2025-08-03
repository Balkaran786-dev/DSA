#include<iostream>
using namespace std;
class A{
private:
   int num;

public:
    A(int n){
        try{
            if(n==0){
                throw "it can't be zero";
            }

            this->num=n;
        }
        catch(const char *str){
            cout<<str<<endl;
        }
    }

    ~A(){
        cout<<"destructor";
    }
};
int main(){
    A a(0);
    return 0;
}
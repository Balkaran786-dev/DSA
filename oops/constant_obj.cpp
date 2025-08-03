#include<iostream>
#include<string.h>
using namespace std;
class A{
    char *p;
    char *q;
    
public:
    A(char *a,char *b){
        p=new char[strlen(a)];
        q=new char[strlen(b)];
        strcpy(p,a);
        strcpy(q,b);
    }

    void show_data()const{
       cout<<p<<" "<<q;
    }
};
int main(){
    
    A const obj("Balkaran","singh");
    obj.show_data();
    return 0;
}


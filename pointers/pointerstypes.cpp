#include<iostream>
using namespace std;
int main(){
 // 1. wild pointer
    int *ptr;  // wild pointer..we just declared it but doesn't initialise
    cout<<ptr<<" "<<*ptr<<endl;


 // 2.Null pointer
    int *p1=NULL;
    int *p2=NULL;
    cout<<p1<<" "<<p2<<endl; //dereferencing a null pointer will give a segmentation error.
    int *p3=0;
    int *p4='\0';
    cout<<p3<<" "<<p4<<endl;


// 3. dangling pointer
    int *ptr1=NULL;
    {
        int x=10;
        ptr1=&x;
    }
    cout<<ptr1<<endl;

// 4. void pointer
    int a=10;
    float b=3.1;
    void *ptr2=&a;
    void *ptr3=&b;
    //we can't dereference the value from void pointer.so we need to typecast it.

    int *integer1=(int *)ptr2;
    float *integer2=(float *)ptr3;
    cout<<*integer1<<" "<<*integer2;
    return 0;
}
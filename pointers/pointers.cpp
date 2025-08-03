#include<iostream>
using namespace std;
int main(){
    int x=89;
    int *ptr=&x;
    cout<<ptr<<" "<<*ptr<<" "<<&ptr<<endl;
    char ch='A';
    char *ptrc=&ch;
    cout<<ptrc<<" "<<*ptrc<<" "<<&ptrc;

     //-----------------------

    int *ptr;
    cout<<ptr<<endl;   //gives u any random address
    int marks=90;
    ptr=&marks;
    cout<<ptr;    // gives you the address of variable marks

     //--------------------------

    int x=56;
    int *ptr=&x;   // here we initialised the pointer variable ptr.
    *ptr=89;   // we can update the value using pointers only if we have already initialised the pointer variable.
    cout<<*ptr;

    //--------------------------

    int x=90;
    int *ptr=&x;
    int *ptra=ptr;   //ptr basically stores address of x and we stored the address of ptr in ptra
    cout<<ptr<<" "<<ptra;
    
    //------------------

    int a=90;
    int y=34;
    int *ptr=&a;
    ptr=8;  // it shows error because ptr is pointer variable which can only stores address
    
    *ptr=&y  // you can store an address in int variable..*/

    //----------------------


    int x,y;
    cin>>x>>y;

    int *ptrx=&x;
    int *ptry=&y;

    int result;
    cin>>result;
    int *ptr_result=&result;
    cout<<ptr_result<<endl;

    *ptr_result=*ptrx+*ptry;

    cout<<result<<" "<<*ptr_result;
    
    return 0;
}
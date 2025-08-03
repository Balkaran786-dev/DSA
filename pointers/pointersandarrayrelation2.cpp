#include<iostream>
using namespace std;
int main(){
    int array[]={1,2,3,4,5};
    int *ptr=(array+2);
    cout<<*ptr<<endl;
    *ptr++;
    cout<<*ptr<<endl;
    --ptr;
    cout<<*ptr;

    int array2[3]={11,12,13};
    int(*p)[3]=&array2;
    cout<<p<<" "<<array2<<" "<<*p<<" "<<*array2;


    

    // int *ptr;
    // cout<<*ptr;


    return 0;
}
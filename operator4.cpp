#include<iostream>
using namespace std;

int main(){

     int a=7;
     cout<<sizeof(a)<<endl; //4

     char name='a';
     cout<<sizeof(name)<<endl; //1

     cout<<(&a)<<endl;

     int b=6;

     cout<<(b++)<<endl; //6
    
     int c=7;
     cout<<(--c)<<endl; //6

     char ch= 4>=5? 'A':'B';
     cout<<ch;

     

    return 0;
}
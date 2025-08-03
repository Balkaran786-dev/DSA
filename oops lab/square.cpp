#include<iostream>
using namespace std;
#define SQUARE(x)  x*x
inline int square(int n){
    return n*n;
}
int main(){
    int num;
    cin>>num;
    cout<<square(num)<<endl;  //using inline function
    cout<<SQUARE(num);        //using MACROS
}


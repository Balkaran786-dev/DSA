#include<iostream>
using namespace std;
int fact(int n){
    int factorial=1;
    if(n==0){
        return 1;
    }
    while(n>0){
        factorial*=n;
        n--;
    }
    return factorial;
}
int nCr(int n,int r){
    int result=fact(n)/( fact(r)*fact(n-r) );
    return result;
}
int main(){
    int n,r;
    cin>>n>>r;
    cout<<nCr(n,r);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int fact(int num){
    int factorial=1;
    if(num==0){
        return 1;
    }
    while(num!=0){
        factorial*=num;
        num--;
    }
    return factorial;
}
int nCr(int n,int r){
    return fact(n)/(fact(r)*fact(n-r));
}
int main(){
    int i,j;
    cin>>i>>j;
    cout<<"Element of "<<i<<"th row and "<<j<<"th column is:"<<nCr(i,j);
    
}

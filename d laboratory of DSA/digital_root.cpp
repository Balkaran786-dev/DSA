#include<iostream>
using namespace std;
int get_dig_root(int n){
    if(n>=0 && n<=9){
        return n;
    }
    return n%10+get_dig_root(n/10);
}
void digital_root(int num){
    if(num<0){
        cout<<"wrong input";
    }
    
    while(num>9){
       num=get_dig_root(num);
    }

    cout<<"The digital root is: "<<num;
}
int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    digital_root(num);
    return 0;
}
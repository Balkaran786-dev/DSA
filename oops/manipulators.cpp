//manipulators used for formatting of data.
#include<iostream>
#include<iomanip>
using namespace std;
int &f(int &x,int &y){
     if(x>y){
        return x;
     }
     else if(x<y){
        return y;
     }
     else{
        return x;
     }
}
    
int main(){
    int m=90,n=100;
    // cout<<(f(m,n))++;
    // cout<<m<<endl<<n;
    int x=10,i=0;
    while(true){
        int x=i;
        cout<<x<<endl;
        i++;
        if(i==6){
            break;
        }
    }
    cout<<x;
    return 0;
}

#include<iostream>
using namespace std;

int &max_ele(int &a,int &b){
    return (a>=b? a:b);
}
int main(){
    int a,b;
    cout<<"Enter the first and second number: ";
    cin>>a>>b;
    int ans=(++max_ele(a,b));
    cout<<ans;
    return 0;
}
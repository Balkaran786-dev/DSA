#include<bits/stdc++.h>
using namespace std;
double power(double m,int n=2){
    double ans=1;
    while(n--){
       ans*=m;
    }
    return ans;
}
int main(){
    double m;
    int n;
    cout<<"Enter the value of m: "<<endl;
    cin>>m;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    cout<<"The square of "<<m<<" is :- "<<power(m)<<endl;
    cout<<m<<" to the power "<<n<<" is:- "<<power(m,n);
    return 0;
}
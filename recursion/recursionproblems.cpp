#include<iostream>
using namespace std;
void f(int n){
    if(n==0){
       return;
    }
    f(n-1);
    cout<<n<<endl;
}
int main(){
    int n;
    cin>>n;
    f(n);
    return 0;
}

#include<iostream>
using namespace std;
void f(int n,int k){
    //base case
    if(k==0){
       cout<<0;
       return;
    }
    //assumption
    f(n,k-1);
    //self work
    cout<<n*k<<endl;
}
int main(){
    int n,k;
    cin>>n>>k;
    f(n,k);
    return 0;
}

#include<iostream>
using namespace std;
int f(int n){
    if(n==1){
        return n;
    }
    return f(n-1)+((n%2==0)?(-n):n);
}
int main(){
    int n;
    cin>>n;
    cout<<f(n);
    return 0;
}
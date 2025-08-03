#include<bits/stdc++.h>
using namespace std;
bool is_perfect(int n){
        double s=sqrt(n);
        return ((s*s)==n?true : false);
    }
int main(){               //while loop
   /* int n;   
    cin>>n;

    int sum=0;
    int i=1; //loop variable
    while(i<=n) {  //condition
        sum+=i;
        i++;       //updation
    } 
    cout<<sum<<endl;

    int x;
    cin>>x;
    int i=1;
    while(i<=10){
        cout<<x*i<<endl;  //table of x
        i++;
    } */
           // for loop
    // int n;
    // cout<<"enter the number n:"<<endl;
    // cin>>n;
    // int sum=0;
    // for(int i=1;i<=n;i++){
    //     sum+=i;
    // } 
    // cout<<sum<<endl;

    
    cout<<is_perfect(6);
    cout<<is_perfect(24);
    cout<<is_perfect(17);
    return 0;
}
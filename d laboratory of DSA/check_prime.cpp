#include<iostream>  //o(sqrt(n))-Time complexity    o(1)-space complexity
#include<math.h>
using namespace std;
string check_prime(int n){
    int count_of_loop=0;
    if(n<=1){
        cout<<"The count of running loop: "<<count_of_loop<<endl;
        return "NOT PRIME";
    }
    else if(n%2==0 && n!=2){
        cout<<"The count of running loop: "<<count_of_loop<<endl;
        return "NOT PRIME";
    }
    else{
        for(int i=3;i<=sqrt(n);i+=2){
            count_of_loop++;
            if(n%i==0){
                cout<<"The count of running loop: "<<count_of_loop<<endl;
                return "NOT PRIME";
            }
        }
    }
    cout<<"The count of running loop: "<<count_of_loop<<endl;
    return "PRIME";
}
int main(){
    int num;
    cin>>num;
    cout<<check_prime(num);
    cout<<"\nName: Balkaran singh\nRollNo: 23103027\n";
}
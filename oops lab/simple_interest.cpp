#include<iostream>
using namespace std;
struct customer_details{
    int age;
    int principal_amount;
    int time_period;
};
int main(){
    int n;
    cout<<"The number of cutomers are: ";
    cin>>n;
    customer_details customers[n];
    for(int i=0;i<n;i++){    //taking input from user
       cout<<"The age of customer "<<i+1<<" is: ";
       cin>>customers[i].age;
       cout<<"The principal amount of customer "<<i+1<<" is: ";
       cin>>customers[i].principal_amount;
       cout<<"The time period for customer "<<i+1<<" is: ";
       cin>>customers[i].time_period;
    }
    double simple_interest[n];
    for(int i=0;i<n;i++){
        if(customers[i].age>=60){  //senior citizen
            simple_interest[i]=(customers[i].principal_amount*12*customers[i].time_period)/100;
        }
        else{                       //for all other customers
            simple_interest[i]=(customers[i].principal_amount*10*customers[i].time_period)/100;
        }
    }
    for(int i=0;i<n;i++){
        cout<<"The simple interest for "<<i+1<<" customer is: ";
        cout<<simple_interest[i]<<" "<<endl;
    }
}
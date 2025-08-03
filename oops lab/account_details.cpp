#include<bits/stdc++.h>
using namespace std;

// struct account_details
// {
//     long long int account_number;
//     string name;
//     double balance;

// };

// void balance_less_than_100(vector<account_details> customers){
//     cout<<"The customers having less than 100 balance are: "<<endl;
//     for(auto ele:customers){
//         if(ele.balance<100){
//             cout<<"The account number is: "<<ele.account_number<<endl;
//             cout<<"The name of customer is: "<<ele.name<<endl;
//         }
//     }
// }

// void deposit_or_withdrawal(vector<account_details> &customers,long long int acc_num,double amount,int w){
//     for(auto ele:customers){
//         if(ele.account_number==acc_num){
//             if(w==1){
//                 ele.balance+=amount;
//                 cout<<"The total balance is -> "<<ele.balance<<endl;
//             }
//             else if(w==0){
//                 ele.balance-=amount;
//                 cout<<"The total balance is -> "<<ele.balance<<endl;
//                 if(ele.balance<100){
//                     cout<<"Insufficient balance"<<endl;
//                 }
//             }
//         }
//     }
// }
int main(){
    // int n;
    // cin>>n;
    // vector<account_details> customers;
    // while(n--){
    //      account_details c;
    //      customers.push_back(c);
    // }
    

    // for(auto &ele:customers){
    //     cin>>ele.account_number>>ele.balance>>ele.name;
    // }

    // balance_less_than_100(customers);
    
    // long long int acc_num;
    // double amount;
    // int w;
    // cout<<"Enter the account number: ";
    // cin>>acc_num;
    // cout<<"Enter the amount: ";
    // cin>>amount;
    // cout<<"Enter 1 for deposit or 0 for withdrawal :";
    // cin>>w;
    
    // deposit_or_withdrawal(customers,acc_num,amount,w);
    int arr[9];
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
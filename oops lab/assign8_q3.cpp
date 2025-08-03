#include<iostream>
#define ll long long int
using namespace std;
class Bank_Account{
    string depositer;
    ll account_number;
    string account_type;
    ll amount;

    public:
    Bank_Account(string name,ll account_number,string account_type,ll amount){
        this->depositer=name;
        this->account_number=account_number;
        this->account_type=account_type;
        this->amount=amount;
    }

    void deposit(ll additional_amount){
        this->amount+=additional_amount;
    }

    void withdraw(ll deduction_amount){
        if(this->amount<deduction_amount){
            cout<<"You dont have enough money"<<endl;
            return;
        }
        this->amount-=deduction_amount;
        cout<<"The remaining balance after deduction is:- "<<this->amount<<endl;
    }
    
    void display(){
        cout<<"The name of the depositor is: "<<this->depositer<<endl;
        cout<<"The balance is: "<<this->amount<<endl;
    }
    ~Bank_Account(){
        cout<<"Destructor is called"<<endl;
    }
};
int main(){
    Bank_Account *account1 = new Bank_Account("Balkaran",23103027,"Savings", 50000);
    
    void (Bank_Account::*depositPtr)(ll) = &Bank_Account::deposit;
    (account1->*depositPtr)(2000);

    account1->withdraw(3000);
    account1->display();


    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Accounts{
   public:

    Accounts(){
        cout<<"Account class"<<endl;
    }
};

class Saving_Accounts:public Accounts{
   public:

   Saving_Accounts(){
    cout<<"Saving Account class"<<endl;
   }
};

class Current_Accounts:public Accounts{
   public:

   Current_Accounts(){
      cout<<"Current Account class"<<endl;
   }
};

class Fixed_deposit: public Accounts{
    public:
    
    Fixed_deposit(){
      cout<<"Fixed Account class"<<endl;
   }
};

class mid_term:public Fixed_deposit{
    public:

    mid_term(){
        cout<<"mid term class"<<endl;
    }
};

class long_term:public Fixed_deposit{
    public:

    long_term(){
        cout<<"long term class"<<endl;
    }
};

class short_term:public Fixed_deposit{
    public:

    short_term(){
        cout<<"short term class"<<endl;
    }
};
int main(){
    cout<<"-------mid term object------"<<endl;
     mid_term mt;

    cout<<"-------current account object------"<<endl;
     Current_Accounts ca;
     
    cout<<"---------long term object-------"<<endl;
     long_term lt;
}
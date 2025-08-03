#include<iostream>
using namespace std;
typedef class{
   int val;
   public:
   void set_data(){
    cin>>this->val;
   }
   void get_data(){
    cout<<"the value is:"<<this->val;
   }
}Number,balk;
int main(){
    Number n1;
    n1.set_data();
    n1.get_data();
    balk n2;
    n2.set_data();
    n2.get_data();
    return 0;
}

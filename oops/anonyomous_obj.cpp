#include<iostream>
using namespace std;
class Number{
   int val;
   public:
   Number(int n){
    val=n;
   }
   int return_data(){
     return val;
   }
   friend Number add(Number,Number);
};
Number add(Number n1,Number n2){
    return Number(n1.val+n2.val);  //anonymous object.
}
int main(){
    Number n1(4),n2(7);
    cout<<add(n1,n2).return_data();
    return 0 ;
}
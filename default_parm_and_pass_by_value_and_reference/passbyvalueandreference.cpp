#include<iostream>
using namespace std;

void changevalue(int z){
    z=100;
}
int main(){
    int a=5;
    changevalue(a);
     cout<<a<<endl;
    //    ans is 5 because of pass by value ek new variable create hoga
    //               jo ke z hoga jisme pehle a ki value copy hogi fer 
    //               100 ki value update hogi...kynki sirf z ki value change hogi a ki nhi.
    //               esliye a ki value 5 hi rhegi....

    return 0;
}

void changevalue(int &z,int &y){
    z=100;
    y=200;
}
int main(){
    int a=5;
    int b=3;
    changevalue(a,b);
    cout<<a<<endl<<b<<endl; /*ans is 100 and 200 because we used ampersand operator which
            make a and z ,b and y to use same memory location and if value of one of them is changed ,it 
            will automatically change the value of other.. */

    
    return 0;
}
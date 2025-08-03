#include<bits/stdc++.h>
using namespace std;
class rectangle{  //destination class
    public:
    int length;
    int breadth;

     rectangle(){
        length=0;
        breadth=0;
     }

     void get_details(){
        cout<<"The length of rectangle is:- "<<length<<endl;
        cout<<"The breadth of rectangle is:- "<<breadth<<endl;
     }
};

class square{  //source class
     int side;

     public:

     square(int a){
        side=a;
     }

     int get_side(){
        return side;
     }

     operator rectangle();
};
square::operator rectangle(){
    rectangle r;
    r.length=this->get_side();
    r.breadth=this->get_side();
    return r;
}
int main(){
    int n;
    cout<<"Enter the side of square: ";
    cin>>n;
    square s(n);
    rectangle r;
    r=s;          //conversion
    r.get_details();
    return 0;
}
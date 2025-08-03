#include<iostream>  //firstly it will check the datatypes of arguements if matches ,then okay,
                    //otherwise it do the implicit type conversion.
using namespace std;
class sum{
    public:
    // int add(int x,int y){
    //     return x+y;
    // }
    int add(int x,int y,int z){
        return x+y+z;
    }
    float add(float x,int y){
        return x+y;
    }
    int add(float x,float y){
        return  x+y;
    }
};

int main(){
    sum s;
    cout<<s.add(2.9,3)<<endl;
    // cout<<s.add(2,3,6)<<endl;
    // cout<<s.add(float(2.8),float(3.5))<<endl;
    
    return 0;
}
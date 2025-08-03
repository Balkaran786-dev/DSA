#include<iostream>
using namespace std;
class time{
public:
  int hours;
  int mins;

  time(int t){
    hours=t/60;
    mins=t%60;
  }
};
int main(){
    int x=90;
    time t1(x);
    cout<<"The given equivalent time in form of hrs and mins is:- "<<endl;
    cout<<t1.hours<<"hr "<<t1.mins<<"mins";
    return 0;
}
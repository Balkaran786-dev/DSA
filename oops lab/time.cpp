#include<bits/stdc++.h>
using namespace std;
class TIME{
public:
     int hours;
     int minutes;

     void set_values(int hours,int minutes){
        this->hours=hours;
        this->minutes=minutes;
     }
     
};
TIME add_times(TIME t1,TIME t2){
        int new_hours=t1.hours+t2.hours;
        int new_minutes=t1.minutes+t2.minutes;
        TIME t3;
        
            while(new_minutes>=60){
                new_hours++;
                new_minutes-=60;
            }
        t3.hours=new_hours;
        t3.minutes=new_minutes;
        return t3;
     }
int main(){
    TIME t1,t2;
    int a1,b1,a2,b2;
    cout<<"Give the hours and minutes for Time1: ";
    cin>>a1>>b1;
    cout<<"Give the hours and minutes for Time2: ";
    cin>>a2>>b2;
    t1.set_values(a1,b1);
    t2.set_values(a2,b2);
    TIME t3=add_times(t1,t2);
    cout<<t3.hours%12<<":"<<t3.minutes;
}
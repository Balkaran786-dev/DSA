#include<iostream>
#define ll long long int
using namespace std;
class DM;
class DB{
  public:
   float feet;
   float inches;
   DB(){
    this->feet=0;
    this->inches=0;
   }
   DB(float feet,float inches){
    this->feet=feet;
    this->inches=inches;
   }
   void get_data(){
    cout<<"The distance in feet is: "<<this->feet<<endl;
    cout<<"The distance in inches is: "<<this->inches<<endl;
   }
   friend DB add_operation(DM& , DB&);  //friend function
};
class DM{
    public:
    float meter;
    float centimeter;
    
    DM(float meter,float centimeter){
        this->meter=meter;
        this->centimeter=centimeter;
    }
    void get_data(){
       cout<<"The distance in meter is: "<<this->meter<<endl;
       cout<<"The distance in centimeter is: "<<this->centimeter<<endl;
   }
    friend DB add_operation(DM& , DB&);  //friend function
};
DB add_operation(DM &obj1,DB &obj2){
     
      float new_ft=obj1.meter*3.28;  //meter to feet
      float new_inches=obj1.centimeter*0.3937;  //centimeter to inches

      DB new_obj;
      new_obj.feet=new_ft+obj2.feet;
      new_obj.inches=new_inches+obj2.inches;

      return new_obj;
}
int main(){
    DB obj1(3.45,4.67);
    DM obj2(3,100);
    obj1.get_data();
    obj2.get_data();

    DB new_obj_of_DB=add_operation(obj2,obj1);
    cout<<"After addition operation:-"<<endl;
    cout<<new_obj_of_DB.feet<<"feet "<<new_obj_of_DB.inches<<"inches";
}
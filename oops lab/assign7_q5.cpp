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
   DB add_operation(DM &obj);  //member function
};
class DM{
    
    float meter;
    float centimeter;

    public:

    DM(float meter,float centimeter){
        this->meter=meter;
        this->centimeter=centimeter;
    }
    void get_data(){
       cout<<"The distance in meter is: "<<this->meter<<endl;
       cout<<"The distance in centimeter is: "<<this->centimeter<<endl;
    }
    friend DB DB::add_operation(DM &);  //friend function
};
DB DB::add_operation(DM &obj){
     //converting meter to centimeter
      float new_ft=obj.meter*3.28;
      float new_inches=obj.centimeter*0.3937;

      DB new_obj;
      new_obj.feet=new_ft+this->feet;
      new_obj.inches=new_inches+this->inches;

      return new_obj;
}
int main(){
    DB obj1(3.45,4.67);
    DM obj2(3,100);
    obj1.get_data();
    obj2.get_data();

    cout<<"After addition operation:-"<<endl;
    DB new_obj_of_DB=obj1.add_operation(obj2);

    cout<<new_obj_of_DB.feet<<"feet "<<new_obj_of_DB.inches<<"inches";
}
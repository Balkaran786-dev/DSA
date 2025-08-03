#include<iostream>
using namespace std;
//  1.  basic to class conversion:
//Conversion of primitive data type to user-defined type: 
//To perform this conversion, the idea is to use the constructor to perform type conversion during the object creation.
//source type-> basic datatype.
//destination type-> class or userdefined datatype.

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
    time t1=x;
    cout<<t1.hours<<"hr "<<t1.mins<<"mins";
    return 0;
}

//   2.class to basic datatype:
// source type: user defined datatype
// destination type: basic datatype.
// The normal form of an overloaded casting operator function,
// also known as a conversion function.


#include<iostream>
using namespace std;
class time{
  public:
  int hrs;
  int mins;

  time(int a,int b){
    hrs=a;
    mins=b;
  }

  operator int();  //int() operator is used for Data
                    // conversion of class to primitive
};

time::operator int(){
    return hrs*60+mins;
}

int main(){
    time t1(2,30);
    int x;
    x=t1;  //class to basic datatype
    cout<<x;
    return 0;
}

//  3. class to class conversion:
// In this type, one class type is converted into another class type. It can be done  in 2 ways :
// 1.Using constructor
// 2.Using Overloading casting operator

// 1.Using constructor :

// In the Destination class,we use the constructor method  

// Objects of different types 
// ObjectX=ObjectY;
// Here ObjectX is Destination object and ObjectY is source object

#include<iostream>
using namespace std;
class cgs{
   int mts;
   int cms;

   public:
   cgs(int a,int b){
     mts=a;
     cms=b;
   }

    void getvalues(){
        cout<<"meters-> "<<this->mts<<endl;
        cout<<"centimeters-> "<<this->cms<<endl;
    }
 
    int get_mts(){
      return mts;
    }

    int get_cms(){
        return cms;
    }
    
};
class fps{
  int feet;
  int inches;

  public:
  fps(){
    feet=0;
    inches=0;
  }

  fps(cgs &c){
    int x;
    x=c.get_cms()+c.get_mts()*100;
    x=x/2.5;
    feet=x/12;
    inches=x%12;
  }
  void getvalues(){
        cout<<"feet-> "<<this->feet<<endl;
        cout<<"inches-> "<<this->inches<<endl;
  }
  
};
int main(){
    cgs obj_c(9,10);
    obj_c.getvalues();
    fps obj_f;
    obj_f=obj_c;
    obj_f.getvalues();

    return 0;
}

//2.Using Overloading casting operator
//here,we will be writing the  overloading casting operator function in the source class...
//so we need to overload the destination class in the source class
//Here we should not tell the return type but we returns the overloaded class object 
//i.e. returning value without specifying return type

#include<iostream>
using namespace std;
class minutes{
public:
   int min;
   minutes(){
    min=0;
   }
};
class time{
   int hrs;
   int mins;
  
   public:
   time(int hrs,int mins){
    this->hrs=hrs;
    this->mins=mins;
   }

   operator minutes(){//overloading minute class 
    minutes m;
    m.min=this->hrs*60+this->mins;
    return m;
   }
   
};
int main(){
    time t(2,30);
    minutes m1;
    m1=t; //minute class in destination class and time is source class
    cout<<m1.min;
    return 0;
}


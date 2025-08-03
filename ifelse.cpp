#include<iostream>
using namespace std;
int main() {
    int num;
    cout<<"enter a number:";
    cin>>num;
    if (num%2==0) {
        cout<<"even"<<endl;
    } else {
        cout<<"odd"<<endl;
    }
          //2nd

          
    int age;
    cout<<"Enter age:";
    cin>>age;

    if (age>55){
        cout<<"Senior citizen"<<endl;    //kynki 55 se upr ke compiler ko pata hai ki senior citizen hai toh >18 usme overlap nhi honge.
    }
     else if (age>18) {
        cout<<"Adult"<<endl;    
    } 
    else if (age>12) {
        cout<<"Teenager"<<endl;
    }
     else{
        cout<<"Child"<<endl;
     }
            //3rd


     int marks;
     cout<<"Marks obtained by the student:";
     cin>>marks;

     if (marks>33){
        if (marks>88){
            cout<<"Gracefully passed";
        } 
        else {
            cout<<"Pass";
        }
     }
    else {
        cout<<"fail";
    }
              //4th


    int marks;
    cin>>marks;

    if(marks>33){
        cout<<"pass"<<endl;
    }
    else {
        cout<<"Fail"<<endl;
    }
                            // you can use ternary operator instead of using if-else statement.
    marks>33? cout<<"Pass":cout<<"Fail"; */
                
                //5th


    int num;
    cout<<"enter a number:"<<endl;
    cin>>num;
                // number should be divisible by 2 and 3 both...
    if(num%2==0 && num%3==0) {
        cout<<"divisible by both"<<endl;
    }
    else{
        cout<<"not divisible by both";
    }
    return 0;
}
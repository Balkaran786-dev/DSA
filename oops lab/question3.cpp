#include<iostream>
#define ld long double
using namespace std;
class rectangle{
public:
      ld length;
      ld breadth;
      ld area;

      rectangle(){
        this->length=0;
        this->breadth=0;
        this->area=0;
      }
      rectangle(ld length,ld breadth){
        this->length=length;
        this->breadth=breadth;
        this->area=0;
      }
      rectangle(ld area){
        this->length=0;
        this->breadth=0;
        this->area=area;
      }

};

rectangle fun(rectangle &r1){
    ld area_of_given_rect=r1.length*r1.breadth;
    r1.area=area_of_given_rect;

    rectangle new_rect(area_of_given_rect);
    return new_rect;
}
int main(){
    ld l,b;
    cout<<"The length and breadth of rectangle is: "<<endl;
    cin>>l>>b;
    rectangle r1(l,b);
    rectangle ans_rect=fun(r1);

    cout<<"The area of our new rectangle is: "<<endl;
    cout<<ans_rect.area<<" square units";
    return 0;
}
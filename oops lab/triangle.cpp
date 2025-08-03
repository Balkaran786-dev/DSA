#include<bits/stdc++.h>
using namespace std;
class triangle{
      double s1,s2,s3;
      double area;

      public:

      void get_data(double s1,double s2,double s3){
        this->s1=s1;
        this->s2=s2;
        this->s3=s3;
      }
      
      void find_area(){
        double s=(s1+s2+s3)/2;
        this->area=sqrt(s*(s-s1)*(s-s2)*(s-s3));
      }
      
      void display_area(){
        cout<<"The area of the given triangle is:- "<<this->area;
      }
};
int main(){
    vector<triangle> vec(3);
    for(int i=0;i<3;i++){
        double s1,s2,s3;
        cout<<"Give the three sides:- "<<endl;
        cin>>s1>>s2>>s3;
        vec[i].get_data(s1,s2,s3);
        vec[i].find_area();
        vec[i].display_area();
        cout<<endl;
    }

    return 0;
}
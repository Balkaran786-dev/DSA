#include<iostream>
using namespace std;
class f{
public:
  int x;
  int y;

  void get_data(int &x,int &y){
     x=90;
     y=30;
  }
};
int  main(){
    int x,y;
    f n;
    n.get_data(90,20);

    cout<<n.x<<" "<<n.y;
    
    return 0;
}
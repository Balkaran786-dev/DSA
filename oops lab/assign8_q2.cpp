#include<bits/stdc++.h>
using namespace std;
class Vector_Game{
      vector<float> vec;
  public:
       Vector_Game(int size){
        this->vec.resize(size);
       }

       void create_vector(){
         int n=this->vec.size();
         cout<<"Give the values for your vector:"<<endl;
         for(int i=0;i<n;i++){
            cin>>this->vec[i];
         }
       }

       void modify(int idx,float value){
        if(idx<0 && idx>=this->vec.size())return;
        else{
            this->vec[idx]=value;
        }
       }

       void multiply_by_k(int k){
        for(int i=0;i<this->vec.size();i++){
            this->vec[i]*=k;
        }
       }

        void display(){
            cout<<"here is your vector:"<<endl;
           for(int i=0;i<this->vec.size();i++){
              cout<<this->vec[i]<<" ";
           }
           cout<<endl;
        }
};
int main(){
    Vector_Game V(5);
    void (Vector_Game::*ptr_create)(void)=&Vector_Game::create_vector;
    void (Vector_Game::*ptr_modify)(int,float)=&Vector_Game::modify;
    void (Vector_Game::*ptr_multiply)(int)=&Vector_Game::multiply_by_k;
    void (Vector_Game::*ptr_display)(void)=&Vector_Game::display;

    (V.*ptr_create)();
    (V.*ptr_display)();

    //updation 
    (V.*ptr_modify)(3,2.3);
    (V.*ptr_multiply)(3);
    cout<<"After updation:- "<<endl;
    (V.*ptr_display)();
    return 0;
}
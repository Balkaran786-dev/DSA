#include<iostream>
using namespace std;
class A{
    public:
      class B{
        private:
        int num;
        public:
        void large(int x,int y){
            this->num=x;
            if(y>x){
                this->num=y;
            }
        }

        void show_data(){
            cout<<this->num<<endl;
        }
      };

      void show(){
        cout<<"Hello"<<endl;
      }
};
int main(){
   A a;  //object of outer class.
   a.show();

   A::B obj; //object of inner class.
   obj.large(34,67);
   obj.show_data();
}
// #include<bits/stdc++.h>
// using namespace std;
// class A{
//     int *arr;
//     int n;
// public:
//     A(){
//         cout<<"hello"<<endl;
//     }
//     A(int);
//     void show_data();

//     ~A(){
//         A(); 
//     }
// };

// A::A(int n){
//     this->n=n;
//     arr=new int[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
// }
// void A::show_data(){
//     for(int i=0;i<this->n;i++){
//         cout<<this->arr[i];
//     }
//     cout<<endl;
// }
// int main(){
//     A obj(5);
//     obj.show_data();
//     return 0;
// }

//mam's ppt question

// #include<iostream>
// using namespace std;
// class A{
//   public:
//   static int obj_created;
//   static int obj_destroyed;
//   static int obj_active;
//   A(){
//     obj_active++;
//     obj_created++;
//   }
//   void show_data(){
//     cout<<"Obj_created: "<<obj_created<<endl;
//     cout<<"Obj_active: "<<obj_active<<endl;
//     cout<<"Obj_destroyed: "<<obj_destroyed<<endl;
//   }
//   ~A(){
//     obj_destroyed++;
//     obj_active--;
//   }
// };
// int A::obj_active;
// int A::obj_created;
// int A::obj_destroyed;
// int main(){
//    {
//    A obj1;
//    obj1.show_data();
//    A obj2;
//    obj2.show_data();
//    A obj3;
//    obj3.show_data();
//    }
//    cout<<A::obj_active<<" ";
//    cout<<A::obj_destroyed<<" ";
// }


#include<iostream>
using namespace std;
class A{
    public:
   int **parr;
   int rows;
   int columns;

   A(int n,int m){
     this->rows=n;
     this->columns=m;
     parr=new int*[rows];
     for(int i=0;i<rows;i++){
        parr[i]=new int[columns];
     }
   }
   void get_data();
   void show_data();
   A &add(A a1,A a2);
   ~A(){
      for(int i=0;i<rows;i++){
         delete parr[i];
      }
      delete parr;
   }
};

A &A::add(A a1,A a2){
    for(int i=0;i<this->rows;i++){
        for(int j=0;j<this->columns;j++){
            this->parr[i][j]=a1.parr[i][j]+a2.parr[i][j];
        }
    }
    return *this;
}
void A::get_data(){
    for(int i=0;i<this->rows;i++){
        for(int j=0;j<this->columns;j++){
            cin>>this->parr[i][j];
        }
    }
}
void A::show_data(){
    for(int i=0;i<this->rows;i++){
        for(int j=0;j<this->columns;j++){
            cout<<this->parr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    A obj1(2,2);
    A obj2(2,2);
    obj1.get_data();
    obj2.get_data();
    obj1.show_data();
    obj2.show_data();

    A obj3(2,2);
    obj3.add(obj1,obj2);
    obj3.show_data();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
template<class T>
class Vector{
public:
   T* arr;
   int size;

   Vector(int m){
    size=m;
    arr=new T[m];
   }

   T dotProduct(Vector &v1){
    T d=0;

    for(int i=0;i<size;i++){
        d+=arr[i]*v1.arr[i];
    }
    return d;
   }
};

template<typename t>
t add(t a, t b){
   return a+b;
}
int main(){
   // Vector<float> v1(3);
   // v1.arr[0]=3.4;
   // v1.arr[1]=7.4;
   // v1.arr[2]=6.4;

   // Vector<float> v2(3);
   // v2.arr[0]=8.9;
   // v2.arr[1]=7.4;
   // v2.arr[2]=6.4;

   // cout<<v1.dotProduct(v2);
    cout<<add(67.9,7.8);
    set<int> s;
    accumulate()
}
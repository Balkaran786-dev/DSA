// #include<iostream>
// #include<vector>
// using namespace std;
// void print_ele(vector<int> &v){
//     for(int i=0;i<v.size();i++){
//         cout<<v[i]<<" ";
//     }
//     cout<<endl;
// }
// void f(vector<int> &array,int idx,int &count,int r,vector<int> &v){
//        if(idx>=array.size() && count==r){
//          print_ele(v);
//          v.pop_back();
//          count--;
//          return;
//        }
//        else if(idx>=array.size()){
//         v.pop_back();
//         count--;
//         return;
//        }
//        else if(count==r){
//          print_ele(v);
//          v.pop_back();
//          count--;
//          return;
//        }

//        for(int i=idx;i<array.size();i++){
//           v.push_back(array[i]);
//           count++;
//           f(array,i+1,count,r,v);
//        }
//        count--;
//        v.pop_back();
// }
// int main(){
//     vector<int> vec={1,2,3,4,5};
//     vector<int> v;
//     int count=0;
//     f(vec,0,count,4,v);
//     return 0;
// }


#include<iostream>
#include<vector>
using namespace std;
int main(){
  int j=0;
  for(int i=0;i<5;i++){
    if(i%2==0) continue;
    for(j=1;j<3;j++){
      cout<<"yes"<<" ";
    }
  }
  cout<<j;
  return 0;
}
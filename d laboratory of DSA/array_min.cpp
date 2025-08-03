#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a={2,9,10,23,4,5,67,8,9};
    int min_ele=INT_MAX;
    for(int i=0;i<a.size();i++){
          min_ele=min(min_ele,a[i]);
          cout<<a[i]<<" ";
    }
    cout<<endl;
    int count=0;
    for(int i=0;i<a.size();i++){
          if(a[i]!=min_ele){
            count++;
            a[i]=min_ele-1;
          }
          cout<<a[i]<<" ";
    }
    cout<<"\n"<<count;
}


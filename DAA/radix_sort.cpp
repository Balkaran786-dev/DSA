#include<iostream>  //o(d*n); time complexity   o(n) space
#include<vector>
using namespace std;
void countsort(vector<int> &v,int pos){
    int n=v.size();
    //making a frequency array.
    vector<int> freq(10,0);
    for(int i=0;i<n;i++){
        freq[(v[i]/pos)%10]+=1;
    }

    //making cumulative freq array.
    for(int i=1;i<10;i++){
        freq[i]+=freq[i-1];
    }

    //calculated a sorted array.
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        ans[--freq[(v[i]/pos)%10]]=v[i];
    }

    //copy the ans array to original array.
    for(int i=0;i<n;i++){
        v[i]=ans[i];
    }
}

void radixsort(vector<int> &v){
    //finding max ele.
    int max_ele=INT16_MIN;
    for(auto x:v){
        max_ele=max(x,max_ele);
    }

    for(int pos=1;(max_ele/pos)>0;pos*=10){
        countsort(v,pos);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    radixsort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// void count_sort(vector<int> &v,int pos){
//     vector<int> freq(10,0);
//     for(int i=0;i<v.size();i++){
//         freq[(v[i]/pos)%10]+=1;
//     }

//     for(int i=1;i<10;i++){
//         freq[i]+=freq[i-1];
//     }
    
//     vector<int> ans(v.size());
//     for(int i=v.size()-1;i>=0;i--){
//         ans[--freq[(v[i]/pos)%10]]=v[i];
//     }
    
//     for(int i=0;i<v.size();i++){
//         v[i]=ans[i];
//     }
// }
// void radixsort(vector<int> &v){
//     //finding max ele
//     int max_ele=INT16_MIN;
//     for(int i=0;i<v.size();i++){
//         max_ele=max(max_ele,v[i]);
//     }

//     for(int pos=1;(max_ele/pos)>0;pos*=10){
//         count_sort(v,pos);
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> v(n);
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }
//     radixsort(v);
//     for(int i=0;i<n;i++){
//         cout<<v[i]<<" ";
//     }
//     return 0;
// }

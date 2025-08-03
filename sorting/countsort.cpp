// #include<iostream>
// #include<vector>
// using namespace std;
// void countsort(vector<int> &v){
//     int n=v.size();
//     //finding the max element in vector v..
//     int max_ele=INT16_MIN;
//     for(int i=0;i<n;i++){
//         //max_ele=max(v[i],max_ele);
//        max_ele=max(v[i],max_ele);
//     }
//     //making a frequency array.
//     vector<int> freq(max_ele+1,0);
//     for(int i=0;i<n;i++){
//         freq[v[i]]+=1;
//     }
//     //making cumulative freq array.
//     for(int i=1;i<=max_ele;i++){
//         freq[i]+=freq[i-1];
//     }
//     //calculated a sorted array.
//     vector<int> ans(n);
//     for(int i=n-1;i>=0;i--){
//         ans[--freq[v[i]]]=v[i];
//     }
//     //copy the ans array to original array.
//     for(int i=0;i<n;i++){
//         v[i]=ans[i];
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> v(n);
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }
//     countsort(v);
//     for(int i=0;i<n;i++){
//         cout<<v[i]<<" ";
//     }
//     return 0;
// }


//when you have negative elements.
#include<iostream>
#include<vector>
using namespace std;
void countsort(vector<int> &v){
    int n=v.size();
    //finding min_ele.
    int i=0;
    //finding the max element in vector v..
    int max_ele=INT16_MIN;
    int min_ele=INT16_MAX;
    for(int i=0;i<n;i++){
        //max_ele=max(v[i],max_ele);
       max_ele=max(v[i],max_ele);
       min_ele=min(v[i],min_ele);
    }
    max_ele-=min_ele;
    while(i<n){
        v[i]-=min_ele;
        i++;
    }
    //making a frequency array.
    vector<int> freq(max_ele+1,0);
    for(int i=0;i<n;i++){
        freq[v[i]]+=1;
    }
    //making cumulative freq array.
    for(int i=1;i<=max_ele;i++){
        freq[i]+=freq[i-1];
    }
    //calculated a sorted array.
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        ans[--freq[v[i]]]=v[i];
    }
    //copy the ans array to original array.
    for(int i=0;i<n;i++){
        v[i]=(ans[i]+min_ele);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    countsort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}


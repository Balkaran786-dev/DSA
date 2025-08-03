#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int kth_largest(vector<int> &v,int k){
    priority_queue<int,vector<int>,greater<int>> pq;  //minheap
    for(int i=0;i<=k-1;i++){
        pq.push(v[i]);
    }

    int curr_idx=k;
    while(curr_idx<v.size()){
         pq.push(v[curr_idx]);
         pq.pop();
         curr_idx++;
    }
    
    return pq.top();
}
int main(){
    int n,k;
    cout<<"The size of array is:";
    cin>>n;
    cout<<"The value of k is:";
    cin>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<kth_largest(v,k);
    return 0;
}
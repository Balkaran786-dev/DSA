#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int k_operations(vector<int> v,int k){
    priority_queue<int,vector<int>,greater<int>> pq; //making minheap
    for(auto ele:v){   //inserting ele in minheap.
        pq.push(ele);
    }

    while(k--){   //doing k times operation
      int first_ele=pq.top();
      pq.pop();
      int second_ele=pq.top();
      pq.pop();
      pq.push(first_ele*second_ele);
    }

    while(pq.size()>1){
        pq.pop();
    }
    return pq.top();
}
int main(){
    vector<int> v={2,4,3,1,5};
    int k;
    cin>>k;
    int ans=k_operations(v,k);
    cout<<ans;
    return 0;
}
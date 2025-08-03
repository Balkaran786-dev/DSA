#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> target_pair(vector<int> v,int target){
     
      vector<int> ans(2,-1);
      unordered_map<int,int> um;
      for(int i=0;i<v.size();i++){
           if(um.empty()){
            um[v[i]]=i;
           }
           else if(um.find(target-v[i])!=um.end()){
              ans[0]=um[target-v[i]];
              ans[1]=i;
           }
           else{
              um[v[i]]=i;
           } 
      }
 
      return ans;
}
int main(){
    int n,target_sum;
    cin>>n>>target_sum;
    
    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    vector<int> ans=target_pair(v,target_sum);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}
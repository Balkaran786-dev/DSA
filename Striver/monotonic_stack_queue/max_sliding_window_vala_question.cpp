//MONOTONIC DECREASING DEQUEUE..
#include<iostream> //o(n)-Time complexity o(k)-space complexity
#include<deque>
#include<vector>
using namespace std;
vector<int> max_sliding_window(vector<int> &nums,int k){
   deque<int> dq;
   vector<int> max_ele;
   for(int i=0;i<=k-1;i++){
      while(!dq.empty() && nums[i]>nums[dq.back()]){
         dq.pop_back();
      }
      dq.push_back(i);
   }
   max_ele.push_back(nums[dq.front()]);
   for(int i=k;i<nums.size();i++){
     if(dq.front()==(i-k)) dq.pop_front();
     while(!dq.empty() && nums[i]>nums[dq.back()]){
         dq.pop_back();
      }
      dq.push_back(i);
      max_ele.push_back(nums[dq.front()]);
   }
   return max_ele;
}
int main(){
    int k;
    cin>>k;
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    vector<int> ans=max_sliding_window(nums,k);
    for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<" ";
    }

    return 0;
}
/* 
  INTUITION
  if you have a window in which ele are arranged in increasing orderand window is moving towards right,
  ,then the max ele (present on right side) will never be allow all the elements before it
  to become max because all those elements will not have even a single window in which that max elemnet won't be present.
  so,obviously there is no chance that any of tham become maximum in any window.
  
  One more thing,if after the increasing order,we see some decresing pattern like
  2 3 6 4 1, here 2 and 3 would never be able to become greater ele in any window due to 6 but
  since 4 and 1 being lesser than 6 and present after 6,there are always gonna be some window ,
  in which 4 and 1 will be present without 6 in it,may be any one of them become 
  greatest in that particular window.so,keeping 4 and 1 is important and removing 2 and 3 is reasonable.
*/

  /* APPROACH
   when a new ele comes,if it greater than previously added ele,keeping removing the elements that are lesser than that.
   but when it is smaller than the lastly added ele,we need to keep it in the queue.
   
   Here in window,we are adding ele from back side and removing ele from front side,so a queue structure will be used.Also,there may be 
   possiblilty,there the ele we are adding from it is greater than some previously added ele,we need to remove them from back.
   hence,A deque is used particularly.In the deque,we will add index instead of element.
   
   The front of every single window gives us the greater ele of that window.
   */


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

  
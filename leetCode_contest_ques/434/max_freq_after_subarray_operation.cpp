//1st solution:-
// form all subarrays , and jiska sabse jada profit hoga, we will take it and add to freq of k overall.


//2nd solution:-
// modified kadane algo...
// we need to find the subarray with maximum profit
// profit is the diff between how manny x you r converting to k and how many k you r destroying in that process.

// in original kadane, we use to increase our length of subarray until the cnt becomes less than 0, here cnt is the sum and we need to maximise it.
// here our cnt is basically defining  the profit..


class Solution {
public:
    int max_subarray(vector<int> &nums,int k,int value,int n){
        
        int max_gain=0;
        int current_gain=0;
        for(int i=0;i<n;i++){
            if(nums[i]==value) current_gain++;
            else if(nums[i]==k) current_gain--;

            if(current_gain<0) current_gain=0;
            max_gain=max(current_gain,max_gain);
        }
        return max_gain;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;  //freq mapping
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        int max_freq=0;   //only while converting the ele into k. 
        for(auto ele:mp){
              int val=ele.first;
              if(val!=k){
                max_freq=max(max_freq,max_subarray(nums,k,val,n));
              }
              
        }

        return max_freq+mp[k];
    }
};
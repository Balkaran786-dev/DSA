// esme hume pata hai ki increase kr skte hain kisi element ko
// so, in brute force , you can first sort the ele and then try for all ele,
// how many backward ele, are able to get converted into it(try for all elements, you will iterate backwrd and see), maintaing the max length.



// sliding window, window is incresed when condition is successful
// shrinked when condition gets unsuccessful.
class Solution {
    public:
        int maxFrequency(vector<int>& nums, int k) {
            sort(nums.begin(),nums.end());
            int n=nums.size();
            long long sum=0;
            int max_len=1;
            int l=0,r=0;
            while(r<n){
                sum+=nums[r];
                if(1LL*(sum+k) < ((r-l+1)*1LL*nums[r])){
                    sum-=nums[l];
                    l++;
                }
    
                if(1LL*(sum+k) >= ((r-l+1)*1LL*nums[r])){
                    max_len=max(max_len,r-l+1);
                }
                r++;
            }
    
            return max_len;
        }
    };
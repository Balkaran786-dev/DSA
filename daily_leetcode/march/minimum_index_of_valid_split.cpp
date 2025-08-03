class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n=nums.size();
            int ele=nums[0];
            int cnt=1;
            // booye moore to find the majority ele...
            for(int i=0;i<n;i++){
                 if(cnt==0){
                    ele=nums[i];
                    cnt=1;
                    continue;
                  }
                  if(ele==nums[i]) cnt++;
                  else cnt--;
            }
            int freq=0;
            // finding the freq of ele...
            for(int i=0;i<n;i++){
                if(nums[i]==ele) freq++;
            }

            int curr_freq=0;
            // finding the valid split...
            for(int i=0;i<n-1;i++){
                if(nums[i]==ele){
                    curr_freq++;
                    if((i+1)/2<curr_freq && (n-i-1)/2<freq-curr_freq){
                        return i;
                    }
                }
            }
            return -1;
    
        }
    };
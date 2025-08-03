class Solution {
    public:
        int maximumBeauty(vector<int>& nums, int k) {
    
            // 1st solution was using a prefix array...
            // that's like,
            // for every ele, you have a range , in which you can convert this ele to.
            // in these diff ranges, whichever ele is coming max time, the max freq is 
            // your ans..
            // take , use prefix funda like you did in shifting letter question ... +1 , -1 vala
            // take size of prefix array as 2*10^5   beacuse it is possible that the maximum ele is 10^5 and k is also 10^5
            // you can avoid negative ele ...if you need to mark at negative ele, mark at 0,,,beacuse we r not going to convert our number
            // anyway to negative numbers...since all the ele in array are >=0...

        
            // 2nd solution using sliding window..
            // suppose , u have 
            // two ele l and r,
            // if ( l+k > = r-k ) that means jo l and r ke beech ke ele hinge unhe bhi hum covert kr payega..
            // that means in a sorted array , you need to find the max subarrayu arr[l...R] such that arr[l]+k>= arr[R]-k  or arr[R]-arr[L] <= 2*k,
            // that means jo l hai hume dekhna hai ki uski max value > than ya fer = to honi chaiye r ki min value se...

            
            sort(nums.begin(),nums.end());
            int n=nums.size();
            int length=1;
            int l=0,r=0;
            while(r<n){
                if(nums[r]-nums[l]>2*k){
                    l++;
                }
    
                if(nums[r]-nums[l]<=2*k){
                    length=max(length,r-l+1);
                }
                r++;
            }
    
            return length;
        }
    };
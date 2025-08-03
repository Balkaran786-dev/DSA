// Brute force
// check for every element in the 

class Solution {
    public:
        bool Helper(vector<int> &nums,long long k,int mid,int n,vector<long long> &prefix){
            int left=0;
            int right=mid-1;
            
            while(right<n){
               int middle=(left+right)/2;
               int req=nums[middle];
               long long left_portion,right_portion;
               if(left==0){
                left_portion=(1LL*(middle-left+1)*req - 1LL*prefix[middle]);
               }
               else{
                left_portion=(1LL*(middle-left+1)*req - 1LL*(prefix[middle]-prefix[left-1]));
               }
               right_portion=(1LL*(prefix[right]-prefix[middle])-1LL*(right-middle)*req);
               if(left_portion+right_portion <= k) return true;
               left++;
               right++;
            }
    
            return false;
        }
        int maxFrequencyScore(vector<int>& nums, long long k) {
            int n=nums.size();
            sort(nums.begin(),nums.end());
            vector<long long> prefix(n);
            prefix[0]=nums[0];
            for(int i=1;i<n;i++){
                prefix[i] = nums[i] + prefix[i - 1];
            }
    
            int l=1,h=n;
            int ans=1;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(Helper(nums,k,mid,n,prefix)){
                    l=mid+1;
                    ans=mid;
                }
                else{
                    h=mid-1;
                }
            }
            return ans;
        }
    };
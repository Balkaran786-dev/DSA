// brute force
// o(n^4)->time , o(2*no_of_unique_quads)->space


//better
// o(n^3) time   , o(2*no_of_unique_quads)->space
// using hashset


// optimal
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int j,k,l;
        long long sum;
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n-2;j++){
                if(j!=i+1 && nums[j]==nums[j-1])continue;
                k=j+1;
                l=n-1;
                while(k<l){
                    sum=nums[i]+nums[j];   //in this way,i have done so that the sum doesnot exceed the integer boundary
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(nums[k]==nums[k+1] && k+1<l){
                            k+=1;
                        }
                         k+=1;
                        while(nums[l]==nums[l-1] && l-1>k){
                            l-=1;
                        }
                         l-=1;
                    }
                    else if(sum<target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};
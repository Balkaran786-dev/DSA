// 1st solution:-  o(n^3 * log(no_of_unique_triplets))->time , space -> o(2*no_of_unique_triplets)
// form all triplets:-


// 2nd solution:- o(n^2 * log(no_of_unique_triplets))->time , space -> o(2*no_of_unique_triplets)
// using hashset..



// 3rd optimal solution:-
// o(n^2) time o(1) space

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int j,k,sum;
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1])continue;
            j=i+1;
            k=n-1;
           while(j<k){
             sum=nums[i]+nums[j]+nums[k];
             if(sum==0){
                ans.push_back({nums[i],nums[j],nums[k]});
                while(nums[j]==nums[j+1] && j+1<k){
                    j+=1;
                }
                j+=1;
                while(nums[k]==nums[k-1] && k-1>j){
                    k-=1;
                }
                k-=1;
             }
             else if(sum<0){
                while(nums[j]==nums[j+1] && j+1<k){
                    j+=1;
                }
                j+=1;
             }
             else{
                while(nums[k]==nums[k-1] && k-1>j){
                    k-=1;
                }
                k-=1;
             }
           }  
        }
        return ans;
    }
};
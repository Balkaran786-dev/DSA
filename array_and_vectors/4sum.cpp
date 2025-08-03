#include<bits/stdc++.h>
using namespace std;
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
            bool flag=false;
            for(int j=i+1;j<n-2;j++){
                if(flag && nums[j]==nums[j-1])continue;
                k=j+1;
                l=n-1;
                while(k<l){
                    sum=nums[i]+nums[j];
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
                    else if(sum<target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
                flag=true;
            }
        }
        return ans;
    }
};
int main(){
    vector<int> nums={1000000000,1000000000,1000000000,1000000000};
    int target=0;
    Solution s;
    vector<vector<int>> ans=s.fourSum(nums,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
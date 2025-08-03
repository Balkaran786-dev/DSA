//in this,we doesn't have equal number of positive and negative numbers,the one that left after 
//alternative ordering needs to be placed as it is..

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
        
        if(pos.size()>neg.size()){
            for(int i=0;i<neg.size();i++){
                   nums[2*i]=pos[i];
                   nums[2*i+1]=neg[i];
            }
            int index=2*neg.size();
            for(int i=neg.size();i<pos.size();i++){
                 nums[index++]=pos[i];
            }
        }
        else{
            for(int i=0;i<pos.size();i++){
                   nums[2*i]=pos[i];
                   nums[2*i+1]=neg[i];
            }
            int index=2*pos.size();
            for(int i=pos.size();i<neg.size();i++){
                 nums[index++]=neg[i];
            }
        }
        return nums;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,4,-2,8,-4,6};
    vector<int> ans=s.rearrangeArray(nums);

    for(int i=0;i<nums.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void give_subsets(vector<int> &nums,int idx,vector<int> &temp,vector<vector<int>> &ans){
          if(idx==nums.size()){
            ans.push_back(temp);
            return;
          }

          give_subsets(nums,idx+1,temp,ans);
          temp.push_back(nums[idx]);
          give_subsets(nums,idx+1,temp,ans);
          temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        give_subsets(nums,0,temp,ans);
        return ans;
    }
};
int main(){
    vector<int> v={1,2,3};
    Solution S;
    vector<vector<int>> ans_subset=S.subsets(v);
    for(int i=0;i<ans_subset.size();i++){
        cout<<"{";
        for(int j=0;j<ans_subset[i].size();j++){
            cout<<ans_subset[i][j]<<" ";
        }
        cout<<"}"<<endl;
    }
    cout<<"\nName: Balkaran singh\nRollNo: 23103027\n";   

    return 0;
}
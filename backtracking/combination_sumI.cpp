class Solution {
public:
    void get_combinations(vector<int>& candidates,int target,int sum,int idx,vector<vector<int>> &ans,vector<int> &temp){
    if(sum==target){
        ans.push_back(temp);
        return;
    }

    if(sum>target || idx==candidates.size()){
        return;
    }
    
    temp.push_back(candidates[idx]);
    get_combinations(candidates,target,sum+candidates[idx],idx,ans,temp);//im taking that same idx into consideration,kuynki hum ek element unlimited times le skte hain.
    temp.pop_back();
    get_combinations(candidates,target,sum,idx+1,ans,temp); //jab hamara same index ke value bss krke return back hoga fir mein idx+1 ko call karunga..
  }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;   //2d vector in which we will be storing our combinations
        vector<int> temp;  //temporary vector 
        get_combinations(candidates,target,0,0,ans,temp);
        return ans;
    }
};
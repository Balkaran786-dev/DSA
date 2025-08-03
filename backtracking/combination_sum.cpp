// //by using an extra space of set in which I'm storing all the unique combinations......

// class Solution {
// public:
//    set<vector<int>> st;
// void get_combinations(vector<int>& candidates,int target,int sum,int idx,vector<vector<int>> &ans,vector<int> &temp){
//     if(sum==target){
//         if(st.count(temp)) return;
//         st.insert(temp);
//         ans.push_back(temp);
//         return;
//     }

//     if(sum>target || idx==candidates.size()){
//         return;
//     }
    
//     sum+=candidates[idx];
//     temp.push_back(candidates[idx]);
//     get_combinations(candidates,target,sum,idx+1,ans,temp);
//     sum-=candidates[idx];
//     temp.pop_back();
//     get_combinations(candidates,target,sum,idx+1,ans,temp);
// }

//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(),candidates.end());
//         vector<vector<int>> ans;   //2d vector in which we will be storing our combinations
//         vector<int> temp;  //temporary vector 
//         get_combinations(candidates,target,0,0,ans,temp);
//         return ans;
//     }
// };


//to remove that extra space of set,here is a below approach

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
    get_combinations(candidates,target,sum+candidates[idx],idx+1,ans,temp);
    temp.pop_back();
    //when im not picking,ill discard all the elements similar to previous one.
    int j=idx+1;
    while(j<candidates.size() && candidates[j]==candidates[j-1])j++;  //this is done so that i don't get a similar combination again
    get_combinations(candidates,target,sum,j,ans,temp);
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;   //2d vector in which we will be storing our combinations
        vector<int> temp;  //temporary vector 
        get_combinations(candidates,target,0,0,ans,temp);
        return ans;
    }
};
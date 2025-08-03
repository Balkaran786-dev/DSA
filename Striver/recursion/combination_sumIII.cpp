class Solution {
public:
    void get_combinations(int k,int n,int i,int sum,vector<int> temp,vector<vector<int>>&ans){
        if(k==0){
            if(sum==n){
                ans.push_back(temp);
            }
            return;
        }
        
        if(sum>n || i>9) return;

        temp.push_back(i);
        get_combinations(k-1,n,i+1,sum+i,temp,ans);
        temp.pop_back();
        get_combinations(k,n,i+1,sum,temp,ans);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum=0;
        get_combinations(k,n,1,sum,temp,ans);
        return ans;
    }
};
// time and space similar to combination I question 
class Solution {
public:
    void get_combinations(vector<int> arr,int idx,int n,int x,int sum,vector<int> temp,vector<vector<int>> &ans){
    if(sum==x){
        ans.push_back(temp);
        return;
    }

    if(sum>x || idx==n){
        return;
    }
    
    temp.push_back(arr[idx]);
    get_combinations(arr,idx+1,n,x,sum+arr[idx],temp,ans);
    temp.pop_back();
    int j=idx+1;
    while(j<n && arr[j]==arr[j-1])j++;  //to ensure we don;t have the same combination again
    get_combinations(arr,j,n,x,sum,temp,ans);
    }
   
    vector<vector<int>> combinationSum2(vector<int>& arr, int x) {
            sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> temp;
    int idx=0;
    int sum=0;
    int n=arr.size();
    get_combinations(arr,idx,n,x,sum,temp,ans);
    return ans;
    }
};



// o(nlogn+k*t) time where k is total valid combinations t is avg ken of combination
// o(t+k*t) space k*t for vector of vector and t for internal stack.
#include<bits/stdc++.h>
    void get_combinations(vector<int> arr,int idx,int n,int x,int sum,vector<int> temp,vector<vector<int>> &ans){
    if(sum==x){
        ans.push_back(temp);
        return;
    }

    if(idx==n) return;

    for(int i=idx;i<n;i++){
        if(sum+arr[i]>x) return; // agr ess index ka ele add krne par sum>target ho rha hai, that means agle saare ele par bhi greater than target rhega kyunki all are in sorted order, hence return from here..
        temp.push_back(arr[i]);
        get_combinations(arr,i,n,x,sum+arr[i],temp,ans);
        temp.pop_back();
    }
}
vector<vector<int>> combSum(vector<int> &arr, int x)
{
    // Write your code here.
       sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> temp;
    int idx=0;
    int sum=0;
    int n=arr.size();
    get_combinations(arr,idx,n,x,sum,temp,ans);
    return ans;
}
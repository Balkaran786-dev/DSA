#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    if(n==1) return nums[0];
    else if(n==2) return max(nums[0],nums[1]);

    int a=nums[n-1];
    int b=max(nums[n-2],nums[n-1]);
    int curr=-1;
    for(int i=n-3;i>=0;i--){
        curr=max(0+b,nums[i]+a);
        a=b;
        b=curr;
    }
    return curr;
}

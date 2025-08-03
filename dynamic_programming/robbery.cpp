// #include<iostream>  //TOP DOWN APPROACH
// #include<vector>
// using namespace std;
// vector<int> dp; //global vector for storing the states that have been computed once.
// int max_rob_money(vector<int> houses,int idx){
//     if(idx>=houses.size()){
//         return 0;
//     }
//     if(dp[idx]!=-1){
//         return dp[idx];
//     }
//     return dp[idx]=max(houses[idx]+max_rob_money(houses,idx+2),0+max_rob_money(houses,idx+1));
// }
// int main(){
//     vector<int> v={2,1,1,9};
//     dp.resize(v.size()+3,-1);
//     cout<<max_rob_money(v,0);
//     return 0;
// }

//BOTTOM UP APPROACH

// #include<iostream>  
// #include<vector>
// using namespace std;
// vector<int> dp;   //global vector for storing the states that have been computed once.
// int max_rob_money(vector<int> houses){
//     int n=houses.size();
//     dp.resize(n);
//     dp[n-1]=houses[n-1];
//     dp[n-2]=max(houses[n-1],houses[n-2]);
//     for(int i=n-3;i>=0;i--){
//         dp[i]=max(houses[i]+dp[i+2],0+dp[i+1]);
//     }
//     return dp[0];
// }

// int main(){
//     vector<int> v={2,1,1,9};
//     cout<<max_rob_money(v);
//     return 0;
// }



#include<iostream>  
#include<vector>
using namespace std;
//global vector for storing the states that have been computed once.
int max_rob_money(vector<int> &houses){
    int n=houses.size();
    int a=houses[n-1],b=max(houses[n-1],houses[n-2]);
    int c;
    for(int i=n-3;i>=0;i--){
        c=max(houses[i]+a,b);
        a=b;
        b=c;
    }
    return c;
}
int main(){
    vector<int> v={2,1,7,8,9,1,10};
    cout<<max_rob_money(v);
    return 0;
}






// top down
class Solution {
public:
    vector<int> dp;
    int strategy(vector<int> &nums,int idx,int n){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=max(nums[idx]+strategy(nums,idx+2,n),0+strategy(nums,idx+1,n));
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,-1);
        int idx=0;

        return strategy(nums,idx,n);
    }
};


// bottom up
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[n-1]=nums[n-1];  // ek hi ghar hai
        dp[n-2]=nums[n-2];  // agr 2 ghar hai, toh jo dono mein se bada hoga.
        for(int i=n-3;i>=0;i--){
            dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }
};


//optimised bottom up
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int a=nums[n-1];
        if(n==1) return a;
        int b=max(nums[n-1],nums[n-2]);
        if(n==2) return b;
        int c;
        for(int i=n-3;i>=0;i--){
            c=max(nums[i]+a,b);
            a=b;
            b=c;
        }
        return c;
    }
};
// // class Solution {
// // public:
// //     bool helper(vector<int>& nums,int mid,int p,int n){
// //         int pairs=0;
// //         for(int i=0;i<n-1;i++){
// //             if(nums[i+1]-nums[i]<=mid){
// //                 pairs++;
// //                 i++;
// //             }
// //             if(pairs==p) return true;
// //         }
// //         if(pairs==p) return true;
// //         return false;
// //     }
// //     int minimizeMax(vector<int>& nums, int p) {
// //         int n=nums.size();
// //         sort(nums.begin(),nums.end());
// //         if(n==1 || p==0) return 0;
// //         int l=0;
// //         int r=nums[n-1]-nums[0];
// //         while(l<=r){
// //             int mid=l+(r-l)/2;
// //             if(helper(nums,mid,p,n)){
// //                 r=mid-1;
// //             }
// //             else l=mid+1;
// //         }
// //         return l;
// //     }
// // };

// #include <iostream>
// #include <vector>
// using namespace std;


// int main() {
//     // Generate test case of size 150000: [2, 1, 2, 2, 1, 2, ...]
//     vector<int> nums;
//     for (int i = 0; i < 50000; ++i) {
//         nums.push_back(2);
//         nums.push_back(1);
//         nums.push_back(2);
//     }

//     for(int i=0;i<nums.size();i++){
//         cout<<nums[i]<<",";
//     }
//     return 0;
// }



class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        priority_queue<pair<int, int>> maxNeg; // for negative numbers (store actual negative values)
        priority_queue<pair<int, int>> maxPos; 

        unordered_set<int> eliminated;
       
        int ans = INT_MIN;

        for (int i = m - 1; i < n; ++i) {
        if (nums[i] < 0)
            maxNeg.push({nums[i], i});
        else
            maxPos.push({nums[i], i});
        }

        for (int i = 0; i <= n - m; ++i) {
        while (!maxNeg.empty() && eliminated.count(maxNeg.top().second))
            maxNeg.pop();
        while (!maxPos.empty() && eliminated.count(maxPos.top().second))
            maxPos.pop();

        
        if (nums[i] < 0 && !maxNeg.empty()) {
            int last = maxNeg.top().first;
            ans = max(ans, nums[i] * last);
        }
        if (nums[i] >= 0 && !maxPos.empty()) {
            int last = maxPos.top().first;
            ans = max(ans, nums[i] * last);
        }

        eliminated.insert(i + m - 1);
    }

   
    eliminated.clear();
    
    for (int i = 0; i <= n - m; ++i) {
        
        if (nums[i] < 0)
            maxNeg.push({nums[i], i});
        else
            maxPos.push({nums[i], i});
    }

    for (int i = m - 1; i < n; ++i) {
       
        while (!maxNeg.empty() && eliminated.count(maxNeg.top().second))
            maxNeg.pop();
        while (!maxPos.empty() && eliminated.count(maxPos.top().second))
            maxPos.pop();

        
        if (nums[i] < 0 && !maxNeg.empty()) {
            int first = maxNeg.top().first;
            ans = max(ans, nums[i] * first);
        }
        if (nums[i] >= 0 && !maxPos.empty()) {
            int first = maxPos.top().first;
            ans = max(ans, nums[i] * first);
        }

        eliminated.insert(i - (m - 1));
    }

    return ans;
    }
};©leetcode
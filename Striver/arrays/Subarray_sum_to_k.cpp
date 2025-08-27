// //optimal
// // here you are storing the freq aside to evry prefix sum..you know the concept;

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
        
//         unordered_map<int,int> mp;
//         int n=nums.size();
//         mp[0]=1;
//         int sum=0;
//         int cnt=0;
//         for(int i=0;i<n;i++){
//              sum+=nums[i];
//              cnt+=mp[sum-k];
//              mp[sum]++;
//         }
//         return cnt;
//     }
// };


#include <bits/stdc++.h>
using namespace std;

int getMaximumOnes(string s, int k) {
    int n = s.size();
    vector<int> nearestOneRight(n, -1);

    // Step 1: track nearest '1' to the right
    int nearest = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') nearest = i;
        nearestOneRight[i] = nearest;
    }

    // Step 2: count ones possible after at most k operations
    int countOnes = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            countOnes++;
        } else if (nearestOneRight[i] != -1 && nearestOneRight[i] - i <= k) {
            // reachable from right within k steps
            countOnes++;
            k--;
        }
    }

    return countOnes;
}

int main() {
    string s = "10110000001";
    int k = 4;
    cout << getMaximumOnes(s, k) << endl; // Output: 4
    return 0;
}

// // two pointers + linear search
// // matlab ek baar pehle innser bulshit area ko find kiya left and right pointer set kiye,
// // then , for every element in left portion, you check which point in the right portion suits by lineraly iterating on it



// // two pointers + binary search
// // here, To find a right partner to every point in the left portion, instead of linearly iterating
// // in the right portion, you used binary search since the right portion is sorted,,
// // You can either perform the same on left portion,



// // two pointers...
// // instead of finding a right partner, you used a two pointer aproach, maintaining the min sequence removed..
// class Solution {
//     public:
//         int findLengthOfShortestSubarray(vector<int>& arr) {
//             // firstly find the inner bullshit area, 
//             int n=arr.size();
//             int l=0;
//             int r=n-1;
//             while(l<n-1 && arr[l]<=arr[l+1]) l++;
//             while(r>0 && arr[r-1]<=arr[r]) r--;
    
//             if(l>=r) return 0; 
//             int i=0, j=r;
    
//             int gaps=r;
//             while(i<=l){
//                 while(j<n && arr[j]<arr[i]) j++;
//                 gaps=min(gaps,j-i-1);
//                 i++;
//             }
    
//             return gaps;
//         }
//     };


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int maxFrequency(vector<int>& nums, int k) {
            sort(nums.begin(),nums.end());
            int n=nums.size();
            long long sum=0;
            int max_len=1;
            int l=0,r=0;
            while(r<n){
                sum+=nums[r];
                while(1LL*(sum+k) < ((r-l+1)*1LL*nums[r])){
                    sum-=nums[l];
                    l++;
                }
    
                if(1LL*(sum+k) >= ((r-l+1)*1LL*nums[r])){
                    max_len=max(max_len,r-l+1);
                }
                r++;
            }
    
            return max_len;
        }
    };
int main() {
    Solution solution;

    // Large Test Case: All elements are the same
    vector<int> nums(100000, 1);
    cout << solution.maxFrequency(nums, 100000) << endl; // Expected: 100000

    // Large Test Case: Increasing pattern
    vector<int> nums2(100000);
    for (int i = 0; i < 100000; ++i) {
        nums2[i] = i + 1;
    }
    cout << solution.maxFrequency(nums2, 100000) << endl; // Expected: ~447

    // Large Test Case: All max elements
    vector<int> nums3(100000, 100000);
    cout << solution.maxFrequency(nums3, 100000) << endl; // Expected: 100000

    return 0;
}

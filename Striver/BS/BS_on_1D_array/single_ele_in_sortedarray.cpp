//Brute force toh you can develop




//optimal.
// thing that is used to eliminate one half is this:-
// (even_idx,odd_idx)  such that ele are equal on these two that means you are on left half, and the single ele must be in right half.
// (odd_idx,even_idx)  such that ele are equal on these two that means you are on right half, and the single ele must be in left half.


//first,we check for the required ele before eliminating
// if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]) arr[mid] is the single ele..
// these condition can create problems at 0th and n-1 th index, so we can check those cases before while loop 

//  1, 1, 2, 2, 3, 3, 4, 6, 6, 8, 8
//(even_idx,odd_idx) | | (odd_idx,even_idx) 


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        
        int lo=1;
        int hi=n-2;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];  //this cond doesn't work on 0 and n-1 index, hence both are handled before..

            else if(mid%2==1 && nums[mid]==nums[mid-1] || mid%2==0 && nums[mid]==nums[mid+1]) lo=mid+1;  //you r on left half
            else hi=mid-1;  // you r on right half
        }
        return 0;
    }
};
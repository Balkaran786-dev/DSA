//1st solution:-
//generating all subarrays





//Intuition:-
//written in copy
// 1st case if all were positive, we took the whole array.
// 2nd case if even negatives were presnt with some positive, whole array
// 3rd case if odd negtives, we would need to ignore one negative.
// 4th case if we have zeroes in between, we can't take them in subarray.
// we can solve this using prefix and suffix.


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int max_product=INT_MIN;
        int prefix=1,suffix=1; 
        for(int i=0;i<n;i++){
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;
            prefix*=nums[i];
            suffix*=nums[n-i-1];
            max_product=max(max_product,max(prefix,suffix));
        }
        return max_product;
    }
};
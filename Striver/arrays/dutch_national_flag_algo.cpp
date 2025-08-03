// using normal sort function or any other sorting algo
// o(nlogn) time o(logn) space


// o(2n) time  o(1) space
// taking three variables and counting freq of 0s , 1s and 2s.
// and then traversing back again in array, and placing values as per their freq,



// DNF sort(Dutch National flag sort)
// take three pointers 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
       while(mid<=high){
        if(nums[mid]==0 && mid==low){  // imagine 0,0,1,1,2;  if this condition, wouldn't have been there, it would have destroyed this already sorted array
            mid++;
            low++;
        }
        else if(nums[mid]==2){
            swap(nums[mid],nums[high]);
            high--;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else if(nums[mid]==0 && mid!=low){
            swap(nums[mid],nums[low]);
            low++;
        }
       }
    }
};
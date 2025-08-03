class Solution {
public:

  int min_ele(vector<int> &arr,int lo,int hi){ 
   while(lo<=hi){
    int mid=(hi+lo)/2;
    if(arr[mid]>arr[mid+1]){
        return arr[mid+1];
    }
    else if(arr[mid]<arr[mid-1]){
        return arr[mid];
    }
    else if(arr[mid]>arr[lo]){
        lo=mid+1;
    }
    else if(arr[mid]<arr[hi]){
        hi=mid-1;
    }
    }
    return -1;
    }
    int findMin(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }

        if(nums[0]<nums[nums.size()-1]){
            return nums[0];
        }

        return min_ele(nums,0,nums.size()-1);
    }
};

class Solution {
public:
    int get_peak(vector<int>& nums,int lo,int hi,int n){
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(mid==0){     //you can't handle these outside the while loop
                if(nums[0]>nums[1]) return 0;
                else return 1;
            }
            else if(mid==n-1){   //you can't handle these outside the while loop
                if(nums[n-1]>nums[n-2]) return n-1;
                else return n-2;
            }
            else{
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])return mid;
                else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){ //increasing slope
                     lo=mid+1;
                }
                else{ //decreasing slope
                     hi=mid-1; 
                }
            }
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        else return get_peak(nums,0,nums.size()-1,nums.size());
    }
};
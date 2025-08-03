class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;

        for(int i=0;i<n-1;i++){
              if(!(nums[i] & 1) && !(nums[i+1] & 1)) return false; // both are even
              else if((nums[i] & 1)==1 && (nums[i+1] & 1)==1) return false;  // both are odd
              else if(nums[i] & 1==1 && nums[i+1] & 1==0) continue;
              else continue;
        }
        return true;
    }
};


class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;

        for(int i=0;i<n-1;i++){
              if(nums[i]%2==nums[i+1]%2) return false;
        }
        return true;
    }
};
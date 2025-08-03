//1. my own approach that gave TLE 
//  trying out all possible combinations...
//  o((max_ele)^N)....

class Solution {
public:
    bool can_reach(vector<int> &nums,int idx,int n){
        if(idx>=n-1) return true;
        
        int max_jump=nums[idx];
        for(int i=max_jump;i>=1;i--){
            bool res=can_reach(nums,idx+i,n);
            if(res) return true;
        }

        return false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        return can_reach(nums,0,n);
    }
};


//2.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int max_index=0;  // mein kitne max_index tak phunch skta hun
        for(int i=0;i<n;i++){
             if(i>max_index) return false;  // if jo mera maxIndex hai, voh mera current index se shota means i can't anyway reach here at this index i, so i won't be able to go further as well, so return false

             if(max_index>=n-1) return true;  // matlab mein last index tak phunch skta hun.

             max_index=max(max_index,nums[i]+i); // max ko tabhi update kren when it is greater than previous
        }

        if(max_index>=n-1) return true;  // matlab mein last index tak phunch skta hun.
        return false;
    }
};
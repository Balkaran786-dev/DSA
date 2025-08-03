// 1st solution using for loops , o(n^2) time and o(1) space


//2nd solution using map , o(nlogm)+o(n) time and o(n) space

//3rd solution , we know XOR of two similar ele is 0.
//for ex 1,2,2,3,4,4,1
// if we take XOR of all, we would be left witj 3^0^0^0=3^0=3 ans.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            XOR^=nums[i];
        }
        return XOR;
    }
};

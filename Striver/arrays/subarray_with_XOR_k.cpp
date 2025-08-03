// brute 
// generate all subarrays.



// optimal 
//done and written in daily leetcode question copy.
int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> mp;
    int XOR=0;
    mp[0]=1;
    int count=0;
    int n1=A.size();
    for(int i=0;i<n1;i++){
        XOR^=A[i];
        if(mp.find(XOR^B)!=mp.end()){
            count+=mp[XOR^B];
        }
        mp[XOR]++;
    }
    return count;
}





// very similar question 2588..

// subtract 2^k from both numbers whose kth bit is set means, making their kth bit 0,
// finding subarrray whose ele can be made zero by applying this operation again n again
// is basically equal to taking their Xor, beacuse in Xor, 0 has nothing to say in it, only two 1s can 
// do something.  if a subarray has Xor zero, that means we can make all its elements zero
// by applying this operation again and again,
// so, in this question we need to find the numebr of suabrrays whose XOR is 0.

class Solution {
    public:
        long long beautifulSubarrays(vector<int>& nums) {
            // this problem trim down to how many subarrays are their 
            // whose EXOR is 0
            unordered_map<int,int> mp;
            mp[0]=1;
            int n=nums.size();
            int prefix=0;
            long long subarrays=0;
            for(int i=0;i<n;i++){
               prefix^=nums[i];
               subarrays+=mp[prefix];
               mp[prefix]++;
            }
            return subarrays;
        }
};

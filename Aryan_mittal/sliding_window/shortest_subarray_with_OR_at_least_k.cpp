/*

same as min window substring
problem is,  OR ke operation ko kaise handle krenge,,
kyunki ek baar agr humne 4 numbers ka OR krdiya , jab hum window decrease krenge toh
first ele ke OR ka effect kaise remove krenge...

for that, instead of using bitwise oR,  we will miantain 32 bit vector
and use for our operation...
the decimal value of this 32 bit vector is giving us the current OR result of the current window.

jaise hi OR lena hoga, iss vector mein uss ele ka binary add krdenge
jaise hi OR remove krna  hoga, iss vector mein uss ele ka binary subtract krdenge

kyu??

for ex:-  1,2,2  k=2
         001 010 010
vector 000
         after l=0 r=0
       001
         l=0 r=1
       011 -> 3   isko fer decimal mein kaise convert krenge, jahan 
       non zero hoga , voh manege ek tarah se filled , kis se hoga 
       obviously 1 se... add hum isilye kr rhe hain taki remove krte
        vakt effect dekh ake, agr vahan 5 bhi presnt hain that means
         decimal mein convert krte vakt iss binary number ko hum yaha 1 hi manege....
        l=1 r=1
      010      -> 2
        l=1 r=2
      020      -> 2
        l=2 r=2
      010      -> 2

      ans=1
      
*/
class Solution {
    public:
        int minimumSubarrayLength(vector<int>& nums, int k) {
            vector<int> count(32, 0);
            int start = 0, end = 0, minLength = INT_MAX;
    
            while (end < nums.size()) {
                updateBits(count, nums[end], 1);
                while (start <= end && getVal(count) >= k) {
                    minLength = min(minLength, end - start + 1);
                    updateBits(count, nums[start], -1);
                    start++;
                }
                end++;
            }
    
            return minLength == INT_MAX ? -1 : minLength;
        }
    
    private:
        void updateBits(vector<int>& count, int num, int val) {
            for (int i = 0; i < 32; i++) {
                if ((num >> i) & 1) {  // matlab usko binary mein convert krte krte kon kon si bit 1 aa rhi hai..
                    count[i] += val;
                }
            }
        }
    
        int getVal(const vector<int>& count) {
            int ans = 0;
            for (int i = 0; i < 32; i++) {
                if (count[i] > 0) {
                    ans |= (1 << i);
                }
            }
            return ans;
        }
    };
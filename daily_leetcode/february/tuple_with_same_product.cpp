// o(n^3) without using any extra space...

class Solution {
    public:
        int tupleSameProduct(vector<int>& nums) {
            int n = nums.size(), ans = 0;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < n; i++) {
                for (int j = n - 1; j > i + 2; j--) {
                    int l = i + 1, r = j - 1;
                    int mul = nums[i] * nums[j];
                    while (l < r) {
                        if (nums[l] * nums[r] == mul) {
                            ans += 8;
                            l++, r--;
                        } else if (nums[l] * nums[r] > mul)
                            r--;
                        else
                            l++;
                    }
                }
            }
            return ans;
        }
};

// by using extra space o(n^2);
// you can optimise it also,
// by calculating and updating in the same loop.
/* for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        int mul=nums[i]*nums[j];
        count+=8*(mp[mul]);
        mp[mul]++;
    }
   }
*/

class Solution {
    public:
        int tupleSameProduct(vector<int>& nums) {
            int n=nums.size();
            unordered_map<int,int> mp;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    mp[nums[i]*nums[j]]++;
                }
            }
            
            int cnt=0;
            for(auto ele:mp){
                int count=ele.second;
                cnt+=(8*(count*(count-1))/2);
            }
            return cnt;
        }
};


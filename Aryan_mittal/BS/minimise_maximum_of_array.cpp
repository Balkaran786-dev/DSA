class Solution {
    public:
        bool func(vector<int> &nums, int mid, int n) { // Pass nums by value (copy)
            vector<long long> temp(begin(nums),end(nums));
            for (int i = 0; i < n - 1; i++) {
                if (temp[i] > mid)
                    return false;
    
                long long add = mid - temp[i];
                temp[i + 1] -= add;  // matlab jisko hum decrease kr rhe hain, voh sabse pehle -ve nhi hona chahiye, baad mein agr bn bhi jaye toh koi baat nhi, pehle negative nhi hona chahiye.
            }
            return temp[n - 1] <= mid;
        }
    
        int minimizeArrayValue(vector<int>& nums) {
            int n = nums.size();
            int l = 0, h = *max_element(nums.begin(), nums.end());
            int ans = h;
    
            while (l <= h) {
                int mid = l + (h - l) / 2;
                if (func(nums, mid, n)) {
                    ans = mid;
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return ans;
        }
    };
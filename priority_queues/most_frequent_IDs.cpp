// agr minus freq krenge bhi toh, hum 
// total mein se minus krke usko pq mein dal denge
// agr uske total vali freq pq mein se pehle nikl gayi,
// toh bhi koi panga nhi,hum equality of freq check kar hi rhe hain consider krne se pehle.


#define pp pair<long long, int>

class Solution {
public:

    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        vector<long long> vec(n);
        priority_queue<pp> pq;
        unordered_map<int, long long> mp;

        for (int i = 0; i < n; ++i) {
            mp[nums[i]] += freq[i];
            pq.push({mp[nums[i]], nums[i]});

            if (mp[nums[i]] == 0) {
                mp.erase(nums[i]);
            }

            while (!pq.empty()) {
                auto [count, id] = pq.top();
                if (mp.count(id) && mp[id] == count) {  // jo matlab exist krti hongi and jinki freq bhi reality mein hogi equal hogi, vohi consider krenge
                    vec[i] = count;
                    break;
                }
                pq.pop();
            }

            if (pq.empty()) {
                vec[i] = 0;
            }
        }

        return vec;
    }
};

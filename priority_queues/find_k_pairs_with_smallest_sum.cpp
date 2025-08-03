/*
we know 0,0 pair will give the smallest possible sum
uske baad we can have 1,0 or 0,1 as the candidate,
abb fer aise hi jo min heap se bahar niklega,
uske do possible candidate ban skte hain, i+1,j  and i,j+1

ok , you need to maintain what all pairs has been pushed in the priority queue'
using an unordered set.

*/



#define pp pair<int,pair<int,int>>
struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pp,vector<pp>,greater<pp>> pq;

        int n1=nums1.size();
        int n2=nums2.size();
        
        unordered_set<pair<int,int>, pair_hash>st; 
        vector<vector<int>> vec;
        pq.push({nums1[0]+nums2[0],{0,0}});
        st.insert({0,0});
        while(k--){
            pp temp=pq.top();
            pq.pop();
            int idx1=temp.second.first;
            int idx2=temp.second.second;
            vec.push_back({nums1[idx1],nums2[idx2]});
            if(idx1+1<n1 && !st.count({idx1+1,idx2})){
                pq.push({nums1[idx1+1]+nums2[idx2],{idx1+1,idx2}});
                st.insert({idx1+1,idx2});
            }
            if(idx2+1<n2  && !st.count({idx1,idx2+1})){
                pq.push({nums1[idx1]+nums2[idx2+1],{idx1,idx2+1}});
                st.insert({idx1,idx2+1});
            }
        }
        
        return vec;
    }
};
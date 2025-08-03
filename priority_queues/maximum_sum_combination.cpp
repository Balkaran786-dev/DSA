#define pp pair<int,pair<int,int>>
struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
vector<int> Solution::solve(vector<int> &nums1, vector<int> &nums2, int k) {
    sort(nums1.begin(),nums1.end(),greater<int> ());
    sort(nums2.begin(),nums2.end(),greater<int> ());

    priority_queue<pp> pq;

        int n=nums1.size();
        
        unordered_set<pair<int,int>,pair_hash>st; 
        vector<int> vec;
        pq.push({nums1[0]+nums2[0],{0,0}});
        st.insert({0,0});
        while(k--){
            pp temp=pq.top();
            pq.pop();
            int idx1=temp.second.first;
            int idx2=temp.second.second;
            vec.push_back(temp.first);
            if(idx1+1<n && !st.count({idx1+1,idx2})){
                pq.push({nums1[idx1+1]+nums2[idx2],{idx1+1,idx2}});
                st.insert({idx1+1,idx2});
            }
            if(idx2+1<n  && !st.count({idx1,idx2+1})){
                pq.push({nums1[idx1]+nums2[idx2+1],{idx1,idx2+1}});
                st.insert({idx1,idx2+1});
            }
        }
        
        return vec;
}

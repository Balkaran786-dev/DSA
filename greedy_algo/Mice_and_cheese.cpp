class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<pair<int,int>> vec;
        int n=reward1.size();
        for(int i=0;i<n;i++){
             vec.push_back({reward1[i]-reward2[i],i});
        }

        sort(vec.begin(),vec.end());
        int ans=0;
        for(int i=n-1;i>=n-k;i--){
             ans+=reward1[vec[i].second];
        }

        for(int i=n-k-1;i>=0;i--) ans+=reward2[vec[i].second];

        return ans;
    }
};
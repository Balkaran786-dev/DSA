class Solution {
public:
    int kSimilarity(string s, string t) {
        unordered_set<string> vis;
        queue<pair<string,int>> q;
        q.push({s,0});
        vis.insert(s);

        while(!q.empty()){
            auto [curr,swaps]=q.front();
            q.pop();

            if(curr==t)return swaps;

            int n = curr.size();
            int i=0;
            while(curr[i]==t[i])i++;

            for(int j=i+1;j<n;j++){
                //swaps mismatched only to reduce the number of swaps.
                if(curr[j]==t[i] && curr[j]!=t[j]){
                    string next=curr;
                    swap(next[i],next[j]);
                    if(!vis.count(next)){
                        q.push({next,swaps+1});
                        vis.insert(next);
                    }
                }
            }
        }

        return -1;
    }
};
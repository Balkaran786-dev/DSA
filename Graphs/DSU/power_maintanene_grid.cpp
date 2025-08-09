class Solution {
public:
    int Find(vector<int>& par, int x) {
        return par[x] = (par[x] == x ? x : Find(par, par[x]));
    }
    void Union(vector<int>& par, vector<int>& rank, int a, int b) {
        a = Find(par, a);
        b = Find(par, b);
        if (rank[a] <= rank[b]) {
            par[a] = b;
            rank[b]++;
        } else {
            par[b] = a;
            rank[a]++;
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        int sz=connections.size();
        vector<int> par(c+1);
        vector<int> rank(c+1,1);
        for(int i=0;i<=c;i++) par[i]=i;

        for(int i=0;i<sz;i++){
            Union(par,rank,connections[i][0],connections[i][1]);
        }
        unordered_map<int,vector<int>> mp;
        for(int i=1;i<=c;i++){
            int idx = Find(par,i);
            mp[Find(par,i)].push_back(i);
        }
        for(auto &ele:mp){
            
            sort(ele.second.begin(),ele.second.end(),greater<int> ());
            
        }
        vector<int> ans;
        unordered_set<int> offline;
        for(int i=0;i<queries.size();i++){
            int val=queries[i][0];
            int node=queries[i][1];
            if(val==2){
                offline.insert(node);
            }
            else{
                if(!offline.count(node)){
                    ans.push_back(node);
                }
                else{
                    bool flag = false;
                    int root = Find(par, node);
                    while(!mp[root].empty()){
                        int value = mp[root].back();
                        
                        if(value==node){
                            mp[root].pop_back();
                        }
                        else if(offline.count(value)){
                            mp[root].pop_back();
                        }
                        else{

                            ans.push_back(value);
                            flag = true;
                            break;
                        }
                    }
                    if(!flag){
                        ans.push_back(-1);
                    }
                }
            }
        }
        return ans;
    }
};
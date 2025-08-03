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
    //so we are going from smaller value nodes to larger value nodes.
    // beacuse if two same value nodes are their in a group,
    // we can definitely say their exist a path betwemn them as no larger nodes have been
    // discovered yet.
    // n nodes can have exactly (n)*(n-1)/2 ways , beacuse their is no cycle,
    // nodes existing in different groups can't make a good path.

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size(),edg=edges.size();
        vector<vector<int>> graph(n);

        vector<int> par(n);
        vector<int> rank(n,1);
        for(int i=0;i<n;i++) par[i]=i;

        for(int i=0;i<edg;i++){ //o(edg)
            int u=edges[i][0];
            int v=edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){   //o(n)
            mp[vals[i]].push_back(i);
        }
        int ans=0;
        unordered_set<int> active; // to mark the active nodes
        for(auto ele:mp){
            int value=ele.first;
            for(int node:ele.second){ //o(n) //yeh mark pehle kiya kya pta do same value nodes directly cinnected ho , toh agr yeh pehle nhi krenge toh voh ek dusre ke sath connect nhi ho payengi.
                active.insert(node);
            }

            for(int node:ele.second){   //o(n)  //unn values vali nodes ke neighbouring nodes ke sath UNion lena Jo active ho.
                for(auto neigh:graph[node]){  //o(edg)
                    if(active.count(neigh)){
                        Union(par,rank,neigh,node);
                    }
                }
            }

            unordered_map<int,int> temp;
            for(int node:ele.second){ //o(n)  //abb yeh dekhyaga ek group mein kitni nodes hain.
                temp[Find(par,node)]++;
            }

            for(auto ele:temp){  //o(unique parents)
               if(ele.second>1){
                ans+=((ele.second)*(ele.second-1))/2;
               }
            }
        }

        return ans+n;
    }
};
//using bits to store which nodes are visited...
//we can't just use a single visited set of nodes as a node can be visited multiple times.
//but we need to avoid any loop,
//for that we can use visited set of pair, to avoid the same path again,
//1->0->1->0 to avoid moving from 1 to 0 again,

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int, int>> qu;
        set<pair<int, int>> visited;
        for (int i = 0; i < n; i++) {
            int val = 0 | 1 << i;  //jo bhi node visit ki uski bit ON krdo..
            qu.push({i, val});
            visited.insert({i, val});
        }
        int req=pow(2,n)-1;   //1111 in binary =pow(2,4)-1;
        int level = 0;
        while (!qu.empty()) {
            int sz=qu.size();
            while(sz--){
                auto curr=qu.front(); qu.pop();
                int node=curr.first;
                int val=curr.second;
                if(val==req) return level; //if all nodes are visited
                
                for(auto neigh:graph[node]){
                    int value= val | 1<<neigh;   //ON krdo uss node vali bit ko.
                    if(visited.count({neigh,value})) continue;
                    qu.push({neigh,value});
                    visited.insert({neigh,value});
                }
            }
            level++;
        }
        return level;
    }
};
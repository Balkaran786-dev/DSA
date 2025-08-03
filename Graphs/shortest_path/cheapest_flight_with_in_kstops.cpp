//

class Solution {
public:
    using pp = pair<int,pair<int,int>> ;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
            adj[u].push_back({v,wt});
        }

        int taken=0;
        // priority_queue<pp,vector<pp>,greater<pp>> pq;
        queue<pp> pq;
        vector<int> distance(n,INT_MAX);
        vector<int> via(n,INT_MAX);
        distance[src]=0;
        via[src]=0;
        pq.push({0,{src,taken}});
        while(!pq.empty()){
            pp curr = pq.front();
            pq.pop();

            int dist=curr.first;
            int node=curr.second.first;
            int took=curr.second.second;
            if(node==dst) continue;
            took+=1;
            for(auto ele:adj[node]){
                int neigh=ele.first;
                int wt=ele.second;
                if(took==k+1 && neigh!=dst) continue;
                
                if(dist+wt<distance[neigh]){
                    distance[neigh]=dist+wt;
                    via[neigh]=took;
                    pq.push({dist+wt,{neigh,took}});
                }
                else if(via[neigh]>took){
                    via[neigh]=took;
                    pq.push({dist+wt,{neigh,took}});
                }
                
            }
        }

        if(distance[dst]==INT_MAX) return -1;
        return distance[dst];
    }
};
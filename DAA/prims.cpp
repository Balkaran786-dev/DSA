#include<bits/stdc++.h> //apply when no. of edges >no. of vertices...
// #define int long long int
#define pp pair<int,int>
using namespace std;
vector<list<pair<int,int>>> graph;  //storing vertices and weight in the form of pair
void add_edge(int u,int v,int wt,bool bidir=true){
    graph[u].push_back({v,wt});
    if(bidir){
        graph[v].push_back({u,wt});
    }
}

int prims(int source,int n){

    priority_queue<pp,vector<pp>,greater<pp>> pq;
    vector<int> par(n+1,-1);
    unordered_map<int,int> mp;
    unordered_set<int> visited;

    for(int i=1;i<=n;i++){
        mp[i]=INT16_MAX;
    }

    pq.push({source,0}); //wrong
    par[source]=0;
    mp[source]=0;
    int total_count=0;
    int ans=0;
    
    while(total_count<n && !pq.empty()){
        pp curr=pq.top();
        pq.pop();
        if(!visited.count(curr.second)){
            visited.insert(curr.second);
            total_count++;
            ans+=curr.first;
            for(auto neigh:graph[curr.second]){
                if(!visited.count(neigh.first) && mp[neigh.first]>neigh.second){
                    pq.push({neigh.second,neigh.first});
                    par[neigh.first]=curr.second;
                    mp[neigh.first]=neigh.second;
                }
            }
        }
    }
    return ans;
}

int main(){   //humne yahan 1 based indexing ke chalte,jo hamare nodes hain voh 1 se lekar n tak leye hain
    int n,m;
    cin>>n>>m;
    graph.resize(n+1);
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    int source;
    cin>>source;
    cout<<prims(source,n);
    return 0;
}

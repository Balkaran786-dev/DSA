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

// int prims(int source,int n){
//       //writing the data structures we neeed to use
//       priority_queue<pp,vector<pp>,greater<pp>> pq;  //pair of int store karne ke liye
//       unordered_map<int,int> mp;   //storing node with its discovery wt
//       vector<int> par(n+1);        //storing parents of each node
//       unordered_set<int> vis;      //to mark the nodes jinke sath ek edge final ho gya hai
//       for(int i=1;i<=n;i++){       
//          mp[i]=INT16_MAX;          //sabhi ka wt except source infinity hoga
//       }
//       pq.push({0,source});        
//       int count=0; //n-1   
//       int ans=0;
//       mp[source]=0;
//       while(count<n && !pq.empty()){ //yahan n-1 esliye nhi likha kyunki 1 se n tak hain nodes
//         pp curr=pq.top();
//         pq.pop();
//         if(!vis.count(curr.second)){
//               vis.insert(curr.second);
//               ans+=curr.first;
//               count++;
//               for(auto neigh:graph[curr.second]){
//                 if(!vis.count(neigh.first) && mp[neigh.first]>neigh.second){
//                     pq.push({neigh.second,neigh.first});
//                     mp[neigh.first]=neigh.second;
//                     par[neigh.first]=curr.second;
//                 }
//               }
//         }
//       }
//       return ans;
// }


// int prims(int sorc,int n){  //time-((v+E)logV) space-(V+E) by chatgbt

//     //data structures 
//     priority_queue<pp,vector<pp>,greater<pp>> pq; //pair of weight,vertix
//     unordered_map<int,int> mp;  //vertix,wt
//     vector<int> par(n+1);  //storing parent
//     unordered_set<int> vis;
    
//     for(int i=1;i<=n;i++){ //o(V)
//         mp[i]=INT16_MAX;
//     }

//     pq.push({0,sorc});
//     mp[sorc]=0;
//     par[sorc]=0;
//     int total_count=0;
//     int ans=0;
//     while(total_count<n && !pq.empty()){ //o(V-1)
//         pp curr=pq.top();
//         pq.pop();
//         if(!vis.count(curr.second)){
//             vis.insert(curr.second);
//             total_count++;
//             ans+=curr.first;
//             for(auto neigh:graph[curr.second]){ 
//                 if(!vis.count(neigh.first) && mp[neigh.first]>neigh.second){
//                     pq.push({neigh.second,neigh.first});
//                     mp[neigh.first]=neigh.second;
//                     par[neigh.first]=curr.second;
//                 }
//             }
//         }
//     }
//     return ans;
// }

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
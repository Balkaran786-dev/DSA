#include<bits/stdc++.h>
#define pp pair<int,int> 
using namespace std;
vector<list<pp>> graph;

void add_edge(int u,int v,int wt){
    graph[u].push_back({v,wt});
    graph[v].push_back({u,wt});
}

unordered_map<int,int> dijkstra(int n){
    priority_queue<pp,vector<pp>,greater<pp>> pq;  //dist,node
    unordered_set<int> vis;
    vector<int> via(n);
    unordered_map<int,int> mp;  //node,dist

    for(int i=1;i<n;i++){
        mp[i]=INT16_MAX;
    }

    pq.push({0,0}); //we have considered source as 0,so dist of 0 from source is 0
    mp[0]=0;

    while(!pq.empty()){  //o(Vlogv + Elogv)
        pp curr=pq.top();  
        vis.insert(curr.second);
        pq.pop();
        for(auto neighbour:graph[curr.second]){
            if(!vis.count(neighbour.first) && mp[neighbour.first]>mp[curr.second]+neighbour.second){  //relaxation step
                pq.push({mp[curr.second]+neighbour.second,neighbour.first});
                mp[neighbour.first]=mp[curr.second]+neighbour.second;
                via[neighbour.first]=curr.second;
            } 
        }

    }
    return mp;
}
int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n);
    while(m--){
       int s,d,wt;
       cin>>s>>d>>wt;
       add_edge(s,d,wt);
    }

    unordered_map<int,int> sd=dijkstra(n);
    for(auto ele:sd){
        cout<<ele.first<<" -> "<<ele.second<<endl;
    }
    return 0;
}



#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>

vector<list<pair<int,int>>> graph;
void add_edge(int sorc,int dest,int wt){
    graph[sorc].push_back({wt,dest});
    graph[dest].push_back({wt,sorc});
}

void dijkstra(int n,unordered_map<int,int> &mp){

    priority_queue<pp,vector<pp>,greater<pp>> pq;
    unordered_set<int> vis;
    vector<int> via(n,-1);

    pq.push({0,0});
    mp[0]=0;
    while(!pq.empty()){
        pp curr=pq.top();
        pq.pop();
        if(!vis.count(curr.second)){
           vis.insert(curr.second);
           for(auto neigh:graph[curr.second]){
              if(!vis.count(neigh.second) && mp[neigh.second]>mp[curr.second]+neigh.first){
                  mp[neigh.second]=mp[curr.second]+neigh.first;
                  via[neigh.second]=curr.second;
                  pq.push({mp[curr.second]+neigh.first,neigh.second});
              }
           }
        }
    }
}
int main(){
     int n,m;
     cin>>n>>m;
     graph.resize(n);
     while(m--){
        int sorc,dest,wt;
        cin>>sorc>>dest>>wt;

        add_edge(sorc,dest,wt);
     }

     unordered_map<int,int> mp; //node,dist_from_source
     for(int i=0;i<n;i++){
         mp[i]=INT16_MAX;
     }

     dijkstra(n,mp);
     for(auto ele:mp){
        cout<<ele.first<<"->"<<ele.second<<endl;
     }
}

//SET used for DIJKSTRA
// we can also use a set data stricture
// set also arrange the pairs of dist,node in such a way that smallest distance is at the top
// one advantage, in PQ, if we get a better distnace for a node, we have to just insert the new pair, we can't renove the already inserted pair which won't give us a better ans, so it will just increase our itertio
// but in set, it will remove the previous pair using erase operation but it will tke log n operation, so there will be something give and take in them...


//why Priority queue?? why not simple queue.
// simple queue will also give us the ans,
// but it will consider a lot of unneccessary paths , that will just increase the iterations
// but PQ greedily take the min distances at first and then moves to other, so we can avoid a lot of unneccessary paths.

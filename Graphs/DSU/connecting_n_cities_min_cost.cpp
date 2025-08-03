#include<bits/stdc++.h>
using namespace std;
vector<int> par;
vector<int> Rank;
int find(int x){
    return par[x]=( par[x]==x ? x : find(par[x]));
}
void Union(int a,int b,bool flag=true){
    if(flag){
        a=find(a);
        b=find(b);
        if(a==b) return;
    }
    
    if(Rank[a]<=Rank[b]){
        par[a]=b;
        Rank[b]++;
    }
    else{
        par[b]=a;
        Rank[a]++;
    }
}
bool Is_connected(){
    unordered_set<int> vis;
    for(int i=1;i<par.size();i++){  //starting from 1 beause we are not changing parent of 0 as we r not considering it a city,so if we want to check,strt from 1.
        vis.insert(par[i]);
    }
    if(vis.size()==1) return true;
    else return false;
}
bool sort_cost(vector<int> &v1,vector<int> &v2){  //custom comparator to sort the ector on the basis of third element of every single row.
    return v1[2]<v2[2];
}

int min_cost(vector<vector<int>> &connections,int n){
    if(!Is_connected()) return -1;  //if it is not connected,we may not be able to get a way to connect them.

    for(int i=0;i<=n;i++){  //to remove all the changes you had made in both the vector while checking if it is connected..
        par[i]=i;
        Rank[i]=0;
    }
    sort(connections.begin(),connections.end(),sort_cost);
    int edge_count=0; //minimum kyunki vertices - 1 chahiye hote hain,toh usse jada nhi chahiye hume.
    int ans=0;
    int i=0;
    while(i<connections.size() && edge_count<n-1){
        int sorc_parent=find(connections[i][0]);
        int dest_parent=find(connections[i][1]);
        if(sorc_parent!=dest_parent){
            Union(sorc_parent,dest_parent,false);
            edge_count++;
            ans+=connections[i][2];
        }
        i++;  //doesn't matter you take the edge or not you need to move ahead in the array.
    }
    return ans;
}
int main(){
    int n,m; //n -> cities  m->connections
    cin>>n>>m;
    par.resize(n+1);
    Rank.resize(n+1,0);
    for(int i=0;i<=n;i++){
        par[i]=i;
    }
    vector<vector<int>> connections(m,vector<int> (3));
    for(int i=0;i<m;i++){
        cin>>connections[i][0]>>connections[i][1]>>connections[i][2];
    }
    int i=0;
    while(m--){
        Union(connections[i][0],connections[i][1]);
        i++;
    }
    cout<<min_cost(connections,n);
}
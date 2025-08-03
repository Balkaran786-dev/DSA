#include<bits/stdc++.h>
using namespace std;
vector<int> par;
vector<int> Rank;
int find(int x){
    return par[x]=(par[x]==x? x : find(par[x]));
}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(Rank[a]<=Rank[b]){
        par[a]=b;
        Rank[b]++;
    }
    else{
        par[b]=a;
        Rank[a]++;
    }
}

void connected_comp(){
    unordered_set<int> comp;
    for(int i=0;i<par.size();i++){
        comp.insert(par[i]);
    }

    cout<<comp.size();
}
int main(){
    int n;
    cin>>n; //no. of vertices
    par.resize(n);
    Rank.resize(n,1);
    for(int i=0;i<n;i++){
        par[i]=i;  //all vertices are their parent itself
    }
    int e;
    cin>>e;
    while(e--){
        int v1,v2;
        cin>>v1>>v2;
        Union(v1,v2);
    }

    connected_comp();
    return 0;
}
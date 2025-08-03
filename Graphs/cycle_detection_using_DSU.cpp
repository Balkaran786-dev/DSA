#include<bits/stdc++.h> //Union by rank using path compression
using namespace std;
vector<int> par;
vector<int> Rank;

int find(int x){
    return par[x]=(par[x]==x? x: find(par[x]));
}

bool Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b) return true;
    if(Rank[a]<=Rank[b]){
        par[a]=b;
        Rank[b]++;
    }
    else{
        par[b]=a;
        Rank[a]++;
    }
    return false;
}
int main(){
     int n,m;
     cin>>n>>m;
     //n->vertices m->edges
     par.resize(n);
     Rank.resize(n,0);
     for(int i=0;i<n;i++){
        par[i]=i;  //initially all elements are their own parents
     }
     
     while(m--){
        int a,b;
        cin>>a>>b;
        bool result=Union(a,b);
        if(result==true){
            cout<<"cycle_detected";
            break;
        }
     }
}


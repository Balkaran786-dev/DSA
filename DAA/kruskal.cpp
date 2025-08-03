//apply when no. of edges<no. of vertices that is in sparse graph
#include<bits/stdc++.h>  //time complexity -> o(V+ElogE)
#define ll long long int  
using namespace std;
int find(vector<int> &par,int x){
    return par[x]=(par[x]==x ? x : find(par,par[x]));
}
void Union(vector<int> &par,vector<int> &Rank,int a,int b){  //hum yahan a and b ke jagah siddha parents hi paas krenge agr dono equal nhi hue,
                                         // so no need to calculate the parents of a and b.
    if(Rank[a]<=Rank[b]){
       par[a]=b;
       Rank[b]++;
    }
    else{
       par[b]=a;
       Rank[a]++;
    }
}

struct Edge{
     int sorc;
     int dest;
     int wt;
};

bool cmp(Edge e1,Edge e2){
    return e1.wt<e2.wt;
}

ll kruskal(vector<Edge> &input,int n){  //n -> vertices
    sort(input.begin(),input.end(),cmp);  //ElogE
    vector<int> par(n+1);
    vector<int> Rank(n+1,0);
    for(int i=0;i<=n;i++){          
      par[i]=i;
    }
    int edgecount=0; 
    int i=0; 
    ll ans=0;  
    while(i<input.size() && edgecount<n-1){     
       
          Edge curr=input[i]; 
          int sorc_parent=find(par,curr.sorc);  //o(log*V)
          int dest_parent=find(par,curr.dest);
          if(sorc_parent!=dest_parent){  
            Union(par,Rank,sorc_parent,dest_parent);
            edgecount++;
            ans+=curr.wt;   //we added the weight in the ans variable
          }
          i++; //doesn't matter if you use the edge or not,you need to move ahead in the vector.
    }
    return ans;
}
int main(){
    int n,e;  //n -> vertices   e -> edges
    cin>>n>>e;
    vector<Edge> edgelist(e);
    for(int i=0;i<e;i++){
        cin>>edgelist[i].sorc>>edgelist[i].dest>>edgelist[i].wt;
    }
    cout<<kruskal(edgelist,n);
}


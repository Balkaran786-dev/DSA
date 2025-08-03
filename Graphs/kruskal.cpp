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
    int edgecount=0; //to make a connected graph of n vertices, min n-1 edges are required
    int i=0; //to traverse over the vector of edges
    ll ans=0;  //to store the weights of all the choosen edges
    while(i<input.size() && edgecount<n-1){     //V-1 -> o(Vlog*V) -> o(V)
        //jaese hi edgecount n-1 hoga we will have connected graph,so we'll get out else agr hum vector se bahr aa gye toh bhi we will get out
          Edge curr=input[i]; //obviously this will be having less weight
          int sorc_parent=find(par,curr.sorc);  //o(log*V)
          int dest_parent=find(par,curr.dest);
          if(sorc_parent!=dest_parent){  //it means it won't form a cycle
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




#include<bits/stdc++.h>
using namespace std;
class Edge{
  public:
    int sorc;
    int dest;
    int weight;
    Edge(){
        this->sorc=-1;
        this->dest=-1;
        this->weight=-1;
    }
    Edge(int sorc,int dest,int wt){
        this->sorc=sorc;
        this->dest=dest;
        this->weight=wt;
    }
};
bool cmp(Edge &e1,Edge &e2){
    return e1.weight<e2.weight;
}

int find(int x,vector<int> &par){
    return par[x]=((par[x]==x)?x:find(par[x],par));
}

bool Union(int a,int b,vector<int> &par,vector<int> &rank){
    a=find(a,par);
    b=find(b,par);
    if(a==b) return true;
    if(rank[a]<=rank[b]){
        par[a]=b;
        rank[b]++;
    }
    else{
        par[b]=a;
        rank[a]++;
    }
    return false;
}
int kruskal(){
    int vertices,edges;

    cin>>vertices>>edges;
    vector<Edge> edgelist;
    vector<int> rank(vertices,0);
    vector<int> par(vertices);

    for(int i=0;i<vertices;i++){
        par[i]=i;
    }

    int i=0;
    while(i<edges){
        int sorc,dest,wt;
        cin>>sorc>>dest>>wt;
        Edge e(sorc,dest,wt);
        edgelist.push_back(e);
        i++;
    }
    
    sort(edgelist.begin(),edgelist.end(),cmp);
    i=0;
    int total_wt=0,edgeCount=0;
    while(i<edgelist.size() && edgeCount<vertices-1 ){  //esdges toh hume jitne vertices hain, usse ek kam hi chahiye
        bool res=Union(edgelist[i].sorc,edgelist[i].dest,par,rank);
        if(!res){
           total_wt+=edgelist[i].weight;
           edgeCount++;
        }
        i++;
    }
    return total_wt;
}
int main(){
    cout<<kruskal();

    return 0;
}

//edgecount isiliye rakhe if in case,we have a multigraph,we need only v-1 edges in it.
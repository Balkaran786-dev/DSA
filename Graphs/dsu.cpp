#include<iostream>   //union by rank using path compression
#include<vector>
using namespace std;
// int find(vector<int> &par,int x){   //find the parent of x
//     return  par[x]=(par[x]==x)? x : find(par,par[x]);  //agar value is equal to index return it otherwise call for par[x]
// }

// void Union(vector<int>& par,vector<int>& rank,int a,int b){  
//     a=find(par,a); 
//     b=find(par,b);
//     if(rank[a]<=rank[b]){  //a ka group b mein merge krdo.
//         par[a]=b;
//         rank[b]++;
//     }
//     else{                  //b ka group a mein merge krdo.
//         par[b]=a;
//         rank[a]++;
//     }
// }

int find(vector<int> &par,int x){
    return par[x]=(par[x]==x?x:find(par,par[x]));
}
void Union(vector<int> &par,vector<int> &rank,int a,int b){
    a=find(par,a);
    b=find(par,b);
    if(rank[a]<=rank[b]){
       par[a]=b;
       rank[b]++;
    }
    else{
       par[b]=a;
       rank[a]++;
    }
}
int main(){               
    int n,m;
    //n-> elements m-> queries
    cin>>n>>m;    
    vector<int> par(n+1);  //parent vector that initially contains value equal to its index
    vector<int> rank(n+1,0);  //the rank of all element is initially 0
    for(int i=0;i<=n;i++){
        par[i]=i;
    }
    while(m--){
        string str;
        cin>>str;
        if(str=="Union"){
            int a,b;
            cin>>a>>b;
            Union(par,rank,a,b);  
        }
        else{
            int x;
            cin>>x;
            cout<<find(par,x);
        }
    }
    return 0;
}




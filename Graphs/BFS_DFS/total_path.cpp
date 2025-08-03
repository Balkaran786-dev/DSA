#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>> graph;    //graph
vector<vector<int>> result; //to store all possible  paths
int n;                      //no. of vertices
unordered_set<int> visited; //track all the visited nodes in a path so that hume parent node pe vapas na aa jaye
void add_edge(int source,int dest,bool direct=true){
       graph[source].push_back(dest);
       if(direct){
         graph[dest].push_back(source);
       }
}

//esko ek example lekar samjhna jada samjh ayega.
void dfs(int sorc,int dest,vector<int> &path){
       if(sorc==dest){
        path.push_back(sorc); //path complete krenge
        result.push_back(path);  //result mein ek path add krenge
        path.pop_back();   //last ele ko pop_back kiya,because may be kuch new path aur bn jaye.
        return;  
       }
       path.push_back(sorc);  
       visited.insert(sorc);
       for(auto neighbour:graph[sorc]){
        if(not visited.count(neighbour)){
            dfs(neighbour,dest,path); 
        }
       }
       path.pop_back(); 
       visited.erase(sorc);
       return;
}
void total_path(int source,int destination){
    vector<int> path;
    dfs(source,destination,path);
}
int main(){
    cin>>n;
    graph.resize(n);
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }

    int source,destination;
    cin>>source>>destination;
    total_path(source,destination);
    for(auto path:result){
        for(auto ele:path){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}m
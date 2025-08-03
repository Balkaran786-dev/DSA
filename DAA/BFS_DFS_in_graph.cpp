
// BFS and DFS in graph

#include<bits/stdc++.h>
using namespace std;

class graph{
private:
    int nodes;
    int edges;
    vector<list<int>> adj;
    
public:
    graph(){
        nodes = 0;
        edges = 0;
    }
    graph(int n , int e){
        nodes = n;
        edges = e;
        adj.resize(nodes);
    }

    void add_edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void display(){
        for(int i=0;i<nodes;i++){
            cout<< i<<"->";
            for(auto j : adj[i] ){
                cout<< j <<" ";
            }
            cout<<endl;
        }
    }
    void bfs(int source, vector<bool> &visited){
        queue <int> q;
        q.push(source);
        // visited[source] = true;

        cout<<"BFS traversal starting from node "<<source<<": ";
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            visited[temp] = true; 

            cout<<temp<<" ";
            for (auto i : adj[temp]){
                if (!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
                
            }
        }
        cout<<endl;
    }

    int connected_using_bfs(){
        vector<bool> visited_bfs(nodes,false);
        int count=0 ;
        for (int i=0 ; i<nodes ; i++){
            if (!visited_bfs[i]){
                bfs(i,visited_bfs);
                count++;
            }
        }
        return count;
    }

    void dfs(int source, vector<bool> &visited){
        stack<int> st;
        st.push(source);
        visited[source] = true;

        cout<<"DFS traversal starting from node "<<source<<": ";
        while(!st.empty()){
            int temp = st.top();
            st.pop();
            cout<<temp<<" ";

            for(auto i: adj[temp]){
                if(!visited[i]){
                    st.push(i);
                    visited[i] = true;
                }     
            }
        }
        cout<<endl;
    }

    int connected_using_dfs(){
        vector<bool> visited_dfs(nodes,false);
        int count=0;
        for(int i=0;i<nodes;i++){
            if (!visited_dfs[i]){
                dfs(i,visited_dfs);
                count++;
            }
        } 

        return count;
    }
};


int main(){
    int n,m;
    cout<<"enter number of nodes and edges: ";
    cin>>n>>m;

    graph g(n,m);
    while(m--){
        int s,d;
        cin>>s>>d;
        g.add_edge(s,d);
    }

    g.display();

    cout<<"connected components using bfs: "<<g.connected_using_bfs()<<endl;
    cout<<"connected components using dfs: "<<g.connected_using_dfs();
}
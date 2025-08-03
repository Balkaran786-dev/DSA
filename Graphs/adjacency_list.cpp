// #include<bits/stdc++.h>
// using namespace std;
// vector<list<int>> graph;  //graph
// int n;   //no. of vertices
// void add_edge(int source,int dest,bool is_bidirect=true){ 
//     graph[source].push_back(dest); 
//     if(is_bidirect){
//        graph[dest].push_back(source);
//     }
// }
// void display(){
//     for(int i=0;i<graph.size();i++){
//         cout<<i<<" -> ";
//         for(auto el:graph[i]){
//             cout<<"("<<el.first<<")"<<",";
//         }
//         cout<<endl;
//     }
// }
// int main(){
//     cin>>n;
//     graph.resize(n); 
//     int e;
//     cin>>e;
//     while(e--){
//         int s,d;
//         cin>>s>>d;
//         add_edge(s,d);
//     }
//     display();
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// vector<list<int>> graph;//can represnt weighted as well
// int n;
// unordered_set<int> visited;
// vector<vector<int>> all_paths;
// void add_edge(int source ,int destination,bool bidirectional=true){
//     graph[source].push_back(destination);
//     if(bidirectional){
//         graph[destination].push_back(source);
//     }
// }
// void display(){
//     for(int i=0;i<n;i++){
//         cout<<i<<"->";
//         for(auto neigh:graph[i]){
//              cout<<neigh<<",";
//         }
//         cout<<endl;
//     }
// }

// void dfs(int source,int destination,vector<int> &temp){
//       if(source==destination){
//         temp.push_back(source);
//         all_paths.push_back(temp);
//         temp.pop_back();
//         return;
//       }
//       visited.insert(source);
//       temp.push_back(source);
//       for(auto neigh:graph[source]){
//         if(!visited.count(neigh)){
//             dfs(neigh,destination,temp);
//         }
//       }
//       temp.pop_back();
//       visited.erase(source);
// }
// int main(){
//     cin>>n;
//     graph.resize(n);
//     int e;
//     cin>>e;

//     while(e--){
//         int s,d;
//         cin>>s>>d;
//         add_edge(s,d);
//     }
//     display();
//     vector<int> temp;
//     dfs(0,5,temp);
//     for(int i=0;i<all_paths.size();i++){
//         for(int j=0;j<all_paths[i].size();j++){
//             cout<<all_paths[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

vector<unordered_map<int,int>> graph;
int n;

void add_edge(int s,int d,int wt,bool dir=true){
    graph[s][d]=wt;
    if(dir){
        graph[d][s]=wt;
    }
}
void display(){
    for(int i=0;i<n;i++){
         cout<<i<<"->";
         for(auto neigh:graph[i]){
            cout<<"("<<neigh.first<<","<<neigh.second<<"),";
         }
         cout<<endl;
    }
}
int main(){
    cin>>n;
    graph.resize(n);

    int e;
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;

        add_edge(s,d,wt);
    }

    display();
}
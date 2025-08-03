//to store a node identification as a parent node in this problem,we would need to 
//store a pair of row and column in the set which is not possible as we can't store a pair in a set.
//so,to mark a visited node,we can change its value from 1 to -1. 
#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
int n,m;
vector<vector<int>> graph;
vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}}; //i,j -> i+1,j -> i-1,j -> i,j+1 -> i,j-1;
void dfs(int i,int j){
      if(graph[i][j]==0){
        return;
      }

      graph[i][j]=-1;
       
      if(i+1<n && graph[i+1][j]!=-1 ){
          dfs(i+1,j);
      }
      if(i-1>=0 && graph[i-1][j]!=-1){
          dfs(i-1,j);
      }
      if(j+1<m && graph[i][j+1]!=-1){
          dfs(i,j+1);
      }
      if(j-1>=0 && graph[i][j-1]!=-1){
          dfs(i,j-1);
      }

}
// int total_islands(){
//     int count=0;
//     for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            if(graph[i][j]!=-1 && graph[i][j]!=0){
//                count++;
//                dfs(i,j);
//            }
//        }   
//     }
//     return count;
// } 
int total_islands(){
    int count=0;
    queue<pair<int,int>> qu;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]!=0 && graph[i][j]!=2){
                count++;
                qu.push(make_pair(i,j));
                while(!qu.empty()){
                        auto pair=qu.front();
                        int first=pair.first;
                        int second=pair.second;
                        graph[first][second]=2;
                        qu.pop();
                        for(int i=0;i<4;i++){
                            int new_Row=first+dir[i][0];
                            int new_Col=second+dir[i][1];
                            if(new_Row>=0 && new_Row<n && new_Col>=0 && new_Col<m){
                                if(graph[new_Row][new_Col]!=2 && graph[new_Row][new_Col]!=0){
                                    qu.push(make_pair(new_Row,new_Col));
                                }
                            }
                        }
                }
            }
        }
    }
    return count;
}

int main(){
    cin>>n;
    cin>>m;
    graph.resize(n);
    for(int i=0;i<n;i++){
        graph[i].resize(m);
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
        }
    }
    cout<<total_islands(); 
    return 0;
}
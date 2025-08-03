// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
//     queue<pair<int,int>> qu;
//     void bfs(vector<vector<int>> &ans_vector,vector<vector<int>> &mat){
//           int time=1;
//           while(not qu.empty()){
//             auto ele=qu.front();
//             qu.pop();
//             int row=ele.first;
//             int col=ele.second;
//             if(row==-1 && col==-1){
//                 time++;
//                 qu.push({-1,-1});
//             }
//             else{
//                 for(int d=0;d<4;d++){
//                     int new_Row=row+dir[d][0];
//                     int new_Col=col+dir[d][1];
//                     if(new_Row<0 || new_Col<0 || new_Row>=mat.size() || new_Col>=mat[0].size()) continue;
//                     if(mat[new_Row][new_Col]==2 || mat[new_Row][new_Col]==0) continue;
//                     if(mat[new_Row][new_Col]==1){
//                         ans_vector[new_Row][new_Col]=time;
//                         mat[new_Row][new_Col]=2;
//                         qu.push({new_Row,new_Col});
//                     }
//                 }
//             }
//           }
          
//     }
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         vector<vector<int>> ans_vector(mat.size(),vector<int> (mat[0].size(),0));
//         for(int i=0;i<mat.size();i++){
//             for(int j=0;j<mat[0].size();j++){
//                 if(mat[i][j]==0){
//                     qu.push({i,j});
//                 }
//             }
//         }
//         qu.push({-1,-1});  //to detect the initialisation of next level
//         bfs(ans_vector,mat);
//         return ans_vector;
//     }
// };
// int main(){
//     vector<vector<int>> v={{0,0,0},{0,1,0},{0,0,0}};
//     Solution s;
//     vector<vector<int>> ans=s.updateMatrix(v);
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<ans[0].size();j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }









class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    queue<pair<int,int>> qu;
    void bfs(vector<vector<int>> &ans_vector,vector<vector<int>> &mat){
          int time=1;
          while(not qu.empty()){
            auto ele=qu.front();
            qu.pop();
            int row=ele.first;
            int col=ele.second;
            if(row==-1 && col==-1){
                time++;
                if(!qu.empty()){
                  qu.push({-1,-1});
                }
                else{
                    break;
                }  
            }
            else{
                for(int d=0;d<4;d++){
                    int new_Row=row+dir[d][0];
                    int new_Col=col+dir[d][1];
                    if(new_Row<0 || new_Col<0 || new_Row>=mat.size() || new_Col>=mat[0].size()) continue;
                    if(mat[new_Row][new_Col]==2 || mat[new_Row][new_Col]==0) continue;
                    ans_vector[new_Row][new_Col]=time;
                    mat[new_Row][new_Col]=2;
                    qu.push({new_Row,new_Col});
                }
            }
          }
          
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans_vector(mat.size(),vector<int> (mat[0].size(),0));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    qu.push({i,j});
                }
            }
        }
        qu.push({-1,-1});  //to detect the initialisation of next level
        bfs(ans_vector,mat);
        return ans_vector;
    }
};
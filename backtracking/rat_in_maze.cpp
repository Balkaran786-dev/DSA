// #include<iostream>
// #include<vector>
// using namespace std;
// int f(vector<vector<int>> &v,int i,int j){
//     if(v[i][j]==0 || i==-1 || i==v.size() || j==-1 || j==v.size() || v[i][j]==2){
//         return 0;
//     }
//     else if(i==v.size()-1 && j==v.size()-1){
//         return 1;
//     }
//     v[i][j]=2;
//     int ans= f(v,i+1,j)+f(v,i,j+1)+f(v,i,j+1)+f(v,i-1,j);
//     v[i][j]=1;
//     return ans;
// }
// int main(){
//     vector<vector<int>> v={
//         {1,1,1,1},
//         {0,1,0,1},
//         {0,1,1,1},
//         {0,1,1,1}
//     };
    
//     cout<<f(v,0,0);
//     return 0;
// }

#include<iostream>
#include<vector>
using namespace std;
bool CanWeGo(int a,int b,vector<vector<int>> &v){
      return a>=0 && b>=0 && a<v.size() && b<v.size() && v[a][b]==1;
}
int f(vector<vector<int>> &v,int i,int j){
     int n=v.size();
     if(i==n-1 && j==n-1){
        return 1;
     }
     int ans=0;
     v[i][j]=2;
     if(CanWeGo(i-1,j,v)){
        ans+=f(v,i-1,j);
     }
     if(CanWeGo(i+1,j,v)){
        ans+=f(v,i+1,j);
     }
     if(CanWeGo(i,j-1,v)){
        ans+=f(v,i,j-1);
     }
     if(CanWeGo(i,j+1,v)){
        ans+=f(v,i,j+1);
     }
     v[i][j]=1;
     return ans;
}
int main(){
    vector<vector<int>> v={
        {1,1,1,1},
        {0,1,0,1},
        {0,1,1,1},
        {0,1,1,1}
    };
    
    cout<<f(v,0,0);
    return 0;
}


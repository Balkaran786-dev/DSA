// using boolean function
// #include<iostream>
// #include<vector>
// using namespace std;
// bool f(vector<vector<int>> &grid,int i,int j,int n,int count){

//     if(i<0 || j<0 || i>=n || j>=n || grid[i][j]>=0) return false;

//     if(count == n*n-1){
//         grid[i][j]=count;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 cout<<grid[i][j]<<" ";
//             }
//             cout<<"\n";
//         }
//         return true;
//     }
    
//     grid[i][j]=count;
//     if(f(grid,i-2,j-1,n,count+1)) return true;
//     if(f(grid,i-2,j+1,n,count+1)) return true;
//     if(f(grid,i+2,j+1,n,count+1)) return true;
//     if(f(grid,i+2,j-1,n,count+1)) return true;
//     if(f(grid,i-1,j-2,n,count+1)) return true;
//     if(f(grid,i+1,j-2,n,count+1)) return true;
//     if(f(grid,i+1,j+2,n,count+1)) return true;
//     if(f(grid,i-1,j+2,n,count+1)) return true;
//     grid[i][j]=-1; //agar uper mein se koi bhi call successful nhi hui.toh revert back karenge
//     return false;
// }
// int main(){
//     int n=5;
//     vector<vector<int>> grid(n,vector<int> (n,-1));
//     f(grid,0,0,n,0);
//     return 0;
// }


//using void function 

#include<iostream>
#include<vector>
using namespace std;
void f(vector<vector<int>> &grid,int i,int j,int n,int count){

    if(count == n*n-1){
        grid[i][j]=count;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
        return;
    }
    
    grid[i][j]=count;
    if(i-2>=0 && j-1>=0 && grid[i-2][j-1]==-1) f(grid,i-2,j-1,n,count+1);
    if(i-2>=0 && j+1<grid[0].size() && grid[i-2][j+1]==-1) f(grid,i-2,j+1,n,count+1);
    if(i-1>=0 && j-2>=0 && grid[i-1][j-2]==-1) f(grid,i-1,j-2,n,count+1);
    if(i-1>=0 && j+2<grid[0].size() && grid[i-1][j+2]==-1) f(grid,i-1,j+2,n,count+1);
    if(i+1<grid.size() && j-2>=0 && grid[i+1][j-2]==-1) f(grid,i+1,j-2,n,count+1);
    if(i+2<grid.size() && j-1>=0 && grid[i+2][j-1]==-1) f(grid,i+2,j-1,n,count+1);
    if(i+2<grid.size() && j+1<grid[0].size() && grid[i+2][j+1]==-1) f(grid,i+2,j+1,n,count+1);
    if(i+1<grid.size() && j+2<grid[0].size() && grid[i+1][j+2]==-1) f(grid,i+1,j+2,n,count+1);
    grid[i][j]=-1; //agar uper mein se koi bhi call successful nhi hui.toh revert back karenge
    return;
}

int main(){
    int n=6;
    vector<vector<int>> grid(n,vector<int> (n,-1));
    f(grid,0,0,n,0);
    return 0;
}


#include<iostream>
#include<vector>
using namespace std;
void spiralorder(vector<vector<int>> v){
    int left=0;
    int right=v[0].size()-1;
    int top=0;
    int bottom=v.size()-1;

    int direction=0;
    while(left<=right && top<=bottom){
        if(direction==0){
            for(int col=left;col<=right;col++){
                cout<<v[top][col]<<" ";
            }
            top++;
        }
        else if(direction==1){
            for(int row=top;row<=bottom;row++){
                cout<<v[row][right]<<" ";
            }
            right--;
        }
        else if(direction==2){
            for(int col=right;col>=left;col--){
                cout<<v[bottom][col]<<" ";
            }
            bottom--;
        }
        else{
            for(int row=bottom;row>=top;row--){
                cout<<v[row][left]<<" ";
            }
            left++;
        
        }
        direction=(direction+1)%4;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    spiralorder(v);
    return 0;
}


// #include<iostream>
// #include<vector>
// using namespace std;
// vector<vector<int>> createspiralorder(int n){
    // vector<vector<int>> v(n,vector<int>(n));
    // int left=0;
    // int right=n-1;
    // int top=0;
    // int bottom=n-1;

    // int direction=0;
    // int value=1;
    // while(left<=right && top<=bottom){
    //     if(direction==0){
    //         for(int col=left;col<=right;col++){
    //             v[top][col]=value++;
    //         }
    //         top++;
    //     }
    //     else if(direction==1){
    //         for(int row=top;row<=bottom;row++){
    //             v[row][right]=value++;
    //         }
    //         right--;
    //     }
    //     else if(direction==2){
    //         for(int col=right;col>=left;col--){
    //             v[bottom][col]=value++;
    //         }
    //         bottom--;
    //     }
    //     else{
    //         for(int row=bottom;row>=top;row--){
    //             v[row][left]=value++;
    //         }
    //         left++;
    //     }
    //     direction=(direction+1)%4;
    // }
    // return v;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<vector<int>> ans;
//     ans=createspiralorder(n);
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

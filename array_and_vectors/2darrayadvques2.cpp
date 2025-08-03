// #include<iostream>
// #include<vector>
// using namespace std;
// int findingsum(vector<vector<int>> v,int l1,int r1,int l2,int r2){
//     int sum=0;
//     for(int i=l1;i<=l2;i++){
//         for(int j=r1;j<=r2;j++){
//             sum+=v[i][j];
//         }
//     }
//     return sum;
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> v(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>v[i][j];
//         }
//     }
//     int l1,r1,l2,r2;
//     cin>>l1>>r1>>l2>>r2;
//     cout<<findingsum(v,l1,r1,l2,r2);
//     return 0;
// }

//     //2nd approach by preffix sum array

// #include<iostream>
// #include<vector>
// using namespace std;
// int findingsum(vector<vector<int>> v,int l1,int r1,int l2,int r2){
//     for(int i=0;i<v.size();i++){
//         for(int j=1;j<v[i].size();j++){
//                v[i][j]+=v[i][j-1];
//         }
//     }
//     int sum=0;
//     for(int i=l1;i<=l2;i++){
//            if(r1!=0){ 
//             sum+=(v[i][r2]-v[i][r1-1]);
//            }
//            else{
//             //v[i][r1-1]=0
//             sum+=v[i][r2];
//            }
//     }
//     return sum;
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> v(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>v[i][j];
//         }
//     }
//     int l1,r1,l2,r2;
//     cin>>l1>>r1>>l2>>r2;
//     cout<<findingsum(v,l1,r1,l2,r2);
//     return 0;
// }

// 3rd approach by first taking row wise than column wise preffix sum array

#include<iostream>
#include<vector>
using namespace std;
int findingsum(vector<vector<int>> v,int l1,int r1,int l2,int r2){
    int sum;
    //row wise preffix sum array
    for(int i=0;i<v.size();i++){
        for(int j=1;j<v[i].size();j++){
               v[i][j]+=v[i][j-1];
        }
    }
    // row-column wise preffix sum array
    for(int i=1;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
               v[i][j]+=v[i-1][j];
        }
    }
    //printing row-column preffix sum array
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
               cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    int top_sum=0,left_sum=0,top_left_sum=0;
    if(l1!=0) {
        top_sum+=v[l1-1][r2];
    }
    if(r1!=0) {
        left_sum+=v[l2][r1-1];
    }    
    if(l1!=0 && r1!=0) {
        top_left_sum+=v[l1-1][r1-1];
    }

    sum=v[l2][r2]- top_sum - left_sum + top_left_sum;

    return sum;
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
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    cout<<findingsum(v,l1,r1,l2,r2);
    return 0;
}

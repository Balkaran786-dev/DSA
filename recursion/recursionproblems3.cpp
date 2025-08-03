//1.
// #include<iostream>
// using namespace std;
// int f(int arr[],int idx,int n,int x){
//     if(idx==n){
//         return 0;
//     }
//     return (arr[idx]==x)||f(arr,idx+1,n,x);
// }
// int main(){
//     int n;
//     cin>>n;
//     int x;
//     cin>>x;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     cout<<f(arr,0,n,x);
//     return 0;
// }

// //2.
// #include<iostream>
// #include<vector>
// using namespace std;
// void f(int arr[],int idx,int n,int sum,vector<int> &v){
//     if(idx==n){
//         v.push_back(sum);
//         return;
//     }
   
//     f(arr,idx+1,n,sum+arr[idx],v);
//     f(arr,idx+1,n,sum,v);
// }
// int main(){
//     int arr[]={1,2,3};
//     vector<int> v;
//     f(arr,0,3,0,v);
//     for(int i=0;i<v.size();i++){
//         cout<<v[i]<<" ";
//     }
//     return 0;
// }
// //3.
// #include<iostream>
// using namespace std;
// int f(int i,int j,int n,int m){
//       if(i==n || j==m) return 0;
//       if(i==n-1 || j==m-1) return 1;

//       return f(i+1,j,n,m)+f(i,j+1,n,m);
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     cout<<f(0,0,n,m);
//     return 0;
// }

#include<iostream>
using namespace std;
bool f(int arr[],int idx,int n,int x){
    if(idx==n-1){
       return (arr[idx]==x);
    }
    bool result=(arr[idx]==x) || f(arr,idx+1,n,x);
    return result;
}
int main(){
    int x;
    cin>>x;
    int arr[]={1,2,3,4,5,6,7};
    cout<<f(arr,0,7,x);
    return 0;
}
// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int> dp; //global vector
// int f(vector<int> heights,int idx,int k){
//     if(idx==heights.size()-1){
//         return 0;
//     }
    
//     if(dp[idx]!=-1){
//         return dp[idx];
//     }
//     int min_possible_cost=INT16_MAX;
//     for(int i=1;i<=k;i++){
//         if(idx+i<=heights.size()-1){
//             min_possible_cost=min(min_possible_cost,abs(heights[idx]-heights[idx+i])+f(heights,idx+i,k));
//         }
//         else{
//             break;
//         }
//     }
//     return dp[idx]=min_possible_cost;
// }
// int main(){
//     int n,k;
//     cin>>n>>k;
//     vector<int> stone_heights(n);
//     dp.resize(n+10,-1);
//     for(int i=0;i<n;i++){
//         cin>>stone_heights[i];
//     }
//     cout<<f(stone_heights,0,k);
// }


#include<iostream>
#include<vector>
using namespace std;
vector<int> dp; //global vector
int f(vector<int> heights,int k){
    int n=heights.size();
    dp[n-1]=0;
    dp[n-2]=abs(heights[n-2]-heights[n-1]);
    
    for(int i=n-3;i>=0;i--){
        int min_ele=INT16_MAX;
        for(int j=1;j<=k;j++){
            if(i+j>=heights.size()) break;
            else min_ele=min(min_ele,abs(heights[i]-heights[i+j])+dp[i+j]);
        }
        dp[i]=min_ele;
    }
    return dp[0];
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> stone_heights(n);
    dp.resize(n);
    for(int i=0;i<n;i++){
        cin>>stone_heights[i];
    }
    cout<<f(stone_heights,k);
}
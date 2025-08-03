#include<iostream>
#include<vector>
using namespace std;
class Solution {
    vector<int> dp;  //to store the already computed problems
public:
    int get_total_ways(int curr,int n){
        if(curr==n || curr==n-1){
            return  dp[curr]=1;
        }
        if(dp[curr]!=-1){
            return dp[curr];
        }
        return dp[curr]=get_total_ways(curr+1,n)+get_total_ways(curr+2,n);
    }
    int climbStairs(int n) {
        dp.resize(n+10,-1);
        return get_total_ways(0,n);
    }
};
int main(){
    int n;
    cin>>n;
    cout<<"The total ways to climb "<<n<<" stairs are:"<<endl;
    Solution s;
    cout<<s.climbStairs(n);
    cout<<"\nName: Balkaran singh\nRollNo: 23103027\n";   
    return 0;
}

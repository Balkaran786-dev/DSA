#include<iostream>   //o(2^N)- Time complexity   o(n)-space for recursion stack
#include<vector>
#include<algorithm>
using namespace std;
void total_targeted_subsets(vector<int> v,int idx,int &count,int curr_sum,int target_sum){
    if(curr_sum==target_sum){
        count++;
        return;
    }
    else if(curr_sum>target_sum || idx==v.size()){
        return;
    }

    total_targeted_subsets(v,idx+1,count,curr_sum,target_sum);
    curr_sum+=v[idx];
    total_targeted_subsets(v,idx+1,count,curr_sum,target_sum);
    curr_sum-=v[idx];
}
int main(){
    int target_sum;
    cout<<"The target sum is:";
    cin>>target_sum;

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end(),greater<int> ());
    int count=0;
    total_targeted_subsets(v,0,count,0,target_sum);
    cout<<count;
    return 0;
}
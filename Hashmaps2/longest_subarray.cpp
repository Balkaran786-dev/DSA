#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int longest_subarray(vector<int> &v){
    unordered_map<int,int> mp;
    int ans=0;
    mp[v[0]]=0;
    mp[0]=-1;
    for(int i=1;i<v.size();i++){
        v[i]+=v[i-1];
        if(mp.count(v[i])){
            ans=max(ans,i-mp[v[i]]);
        }
        else{
            mp.insert(make_pair(v[i],i));
        }
    }
    return ans;
}
int main(){
    // int n;
    // cin>>n;
    
    // vector<int> v(n);

    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    // }
    // int ans=longest_subarray(v);
    // if(ans!=INT16_MIN){
    //     cout<<ans;
    // }
    // else{
    //     cout<<'0';
    // }

    unordered_map<char,int> mp;
    cout<<mp.size()<<" ";
    mp['a']++;
    mp['b']++;
    cout<<mp.size()<<" ";
    mp['b']--;
    cout<<mp.size()<<" ";
    return 0;
}
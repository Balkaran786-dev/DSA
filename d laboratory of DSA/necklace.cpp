#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v={1,5,3,4,2};
    int n=v.size();
    int k;
    cin>>k;
    k=k%n;
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+n-k);
    reverse(v.begin()+n-k,v.end());
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
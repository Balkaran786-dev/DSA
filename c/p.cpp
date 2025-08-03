#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size:";
    cin>>n;
    vector<int> v(n+1,0);  // we initialize our vector with all inputs equal to 0..
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    //finding prefixsumarray
    for(int i=1;i<n;i++){
        v[i]+=v[i-1];
    }

    int q;
    cout<<"enter number of queries:";
    cin>>q;
    while(q>0){
        int l,r;
        cout<<"l:";
        cin>>l;
        cout<<"r:";
        cin>>r;
        int ans;
        ans=v[r]-v[l-1];
        cout<<ans<<endl;
        q--;
    }

    return 0;
}
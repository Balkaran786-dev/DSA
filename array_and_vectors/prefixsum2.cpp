#include<iostream>
#include<vector>
using namespace std;
bool checkPreffixSuffixSum(vector<int> &v){
    int total_sum=0;
    bool result=false;
    for(int i=0;i<v.size();i++){
        total_sum+=v[i];
    }
    int prefix_sum=0;
    for(int i=0;i<v.size();i++){
        prefix_sum+=v[i];
        int suffix_sum=total_sum-prefix_sum;
        if(suffix_sum==prefix_sum){
            result=true;
            break;
        }
        else{
            continue;
        }
    }
    return result;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=1;i<=n;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
   cout<<checkPreffixSuffixSum(v);
}



#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size:";
    cin>>n;
    vector<int> v(n+1,0);  // we initialize our vector with all inputs equal to 0..
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    //finding prefixsumarray
    for(int i=1;i<=n;i++){
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
        cout<<v[r]-v[l-1]<<endl;
        q--;
    }

    return 0;
}
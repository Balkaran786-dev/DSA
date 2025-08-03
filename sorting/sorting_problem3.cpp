#include<bits/stdc++.h>
using namespace std;
void sort_v(vector<int> &v){
    vector<int> freq(2,0);  //at 0 index->-ve values at 1 index-> +ve values
    for(int i=0;i<v.size();i++){
        if(v[i]>=0){
            freq[1]++;
        }
        else{
            freq[0]++;
        }
    }
    freq[1]+=freq[0]; //cumulative freq
    vector<int> new_array(v.size());
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]<0){
           new_array[--freq[0]]=v[i];
        }
        else{
            new_array[--freq[1]]=v[i];
        }
    }
    for(int i=0;i<v.size();i++){
        v[i]=new_array[i];
    }
}
int main(){
    vector<int> v={-8,4,3,-9,1,-2};
    sort_v(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
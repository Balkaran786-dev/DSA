// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// string longest_common_prefix(vector<string> &v){
//     //sorting the array of strings
    // sort(v.begin(),v.end());
    
    // string s1=v[0];
    // string s2=v[v.size()-1];
    // int i=0,j=0;
    // string ans="";
    // while(i<s1.size() && j<s2.size()){
    //    if(s1[i]==s2[j]){
    //     ans+=s1[i];
    //     i++; j++;
    //    }
    //    else{
    //     return ans;
    //    }
    // }
    // return ans;
// }
// int main(){
    // int n;
    // cin>>n;
    // vector<string> v(n);
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    // }
    // cout<<longest_common_prefix(v);
//     return 0;
// }


// //a more optimised solution
#include<iostream>
#include<vector>
using namespace std;
string longest_common_prefix(vector<string> &v){
    string str=v[0];
    int min_length=INT16_MAX;
    int i,j,count;
    int idx=0;
    while(idx<v.size()){
        i=0,j=0,count=0;
        while(i<str.size() && j<v[idx].size() && str[i]==v[idx][j]){
            count++;
            i++,j++;
        }
        min_length=min(min_length,count);
        idx++;
    }
    return str.substr(0,min_length);
}
int main(){

    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<longest_common_prefix(v);
    
    return 0;
}
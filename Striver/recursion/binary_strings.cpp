// 1st solution
// aap saari ki saari strings generate kr lo. i mean at every place ek baar 0 and ek baar 1 rkho
// fer jo jo valid hogi, usko ans mein include kr lena..


//2nd solution
#include<bits/stdc++.h>
void binary_strings(int idx,vector<string> &ans,string temp,int N){
    if(idx==N){
        ans.push_back(temp);
        return;
    }

    binary_strings(idx+1,ans,temp+"0",N);

    if(temp.empty() || temp[idx-1]=='0'){
        binary_strings(idx+1,ans,temp+"1",N);
    }    
}
vector<string> generateString(int N) {
    // Write your code here.
    vector<string> ans;
    string temp="";
    int idx=0;
    binary_strings(idx,ans,temp,N);
    return ans;
}
// 1st solution
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
    
    string s1=strs[0];
    string s2=strs[strs.size()-1];  // sort krne ke baad jo last and first ele hoga unme jo common hoga voh sabhi mein hi hoga common.
    int i=0,j=0;
    string ans="";
    while(i<s1.size() && j<s2.size()){
       if(s1[i]==s2[j]){
        ans+=s1[i];
        i++; j++;
       }
       else{
        return ans;
       }
    }
    return ans;
    }
};

//2nd solution basically first ele ko liya and usko sabhi ele se compare kiya , sabhi se compare krke jitni length sabse kam vali ayi,
// that is longest common in all ele, at least utni sabhi mein hi hogi.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string str=strs[0];
        string ans="";
        int min_length=INT16_MAX;
        int i,j,count;
        int idx=0;
    while(idx<strs.size()){
        i=0,j=0,count=0;
        while(i<str.size() && j<strs[idx].size() && str[i]==strs[idx][j]){
            count++;
            i++,j++;
        }
        min_length=min(min_length,count);
        idx++;
    }
     ans+=str.substr(0,min_length);
     return ans;
    }
};
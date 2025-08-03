//easy one
class Solution {
public:
    string RLE(string &str){
          int n=str.size();
          string ans="";
          
          int l=0,r=0;
          while(r<n){
             char curr=str[l];
             int count=0;
             while(r<n && str[l]==str[r]){
                count++;
                r++;
             }
             ans+=to_string(count)+curr;
             l=r;
          }
          return ans;
    }
    string countAndSay(int n) {
        string ans="1";
        if(n==1) return ans;

        int i=2;
        while(i<=n){
            ans=RLE(ans);
            i++;
        }
        return ans;
    }
};
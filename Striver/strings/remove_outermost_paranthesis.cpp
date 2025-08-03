// my own way....
class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int cnt=0;
        int start=1;
        int i=start;
        string ans="";
        while(i<n){
            if(s[i]=='(') cnt++;
            else cnt--;

            if(cnt==-1){
                ans+=(s.substr(start,i-start));
                start=i+2;
                cnt=0;
                i=start;
                continue;
            }

            i++;
        }
        return ans;
    }
};
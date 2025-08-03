// bss jitna jada deep '(' yeh gya hoga..... utni depth hogi.

class Solution {
public:
    int maxDepth(string s) {
        int max_nesting=0;
        int cnt=0;
        int n=s.size();

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
                max_nesting=max(max_nesting,cnt);
            }
            else if(s[i]==')'){
                cnt--;
            }
        }
        return max_nesting;
    }
};
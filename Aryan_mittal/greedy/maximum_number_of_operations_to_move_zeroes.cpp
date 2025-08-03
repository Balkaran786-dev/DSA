// have some focus on impact of 1's on our operations that are present in the string.

// aryan mittal.

class Solution {
    public:
        int maxOperations(string s) {
            int n=s.size();
            bool first=false;
            int impact=(s[n-1]=='0'?1:0);
            int operations=0;
            for(int i=n-1;i>=0;i--){
                if(s[i]=='1'){
                  int start=i;
                  while(i>=0 && s[i]=='1') i--;
                  operations+=(impact*(start-i));
                  impact++;
                }
            }
            return operations;
        }
};

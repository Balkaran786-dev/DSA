class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;  //yeh rkhega count ( kitne extra hai , if ( comes increment, if ) comes and 
                    // cnt>0 then, decrement count,
                    // to track ki ) kitne extra hai,we will increment req only when ) comes and cnt==0 
        int n=s.size();
        int req=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='(') cnt++;
            else{
                if(cnt>0){
                    cnt--;
                }
                else{
                    req++;  // yeh track rhega ki closing bracket jada toh nhi
                }
            }
        }

        return cnt+req;
    }
};
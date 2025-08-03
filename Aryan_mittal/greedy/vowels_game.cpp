class Solution {
    public:
        bool doesAliceWin(string s) {
            int n=s.size();
            int vowels=0;
            for(int i=0;i<n;i++){
                if(s[i]=='a'|| s[i]=='e'|| s[i]=='i' || s[i]=='o' || s[i]=='u') vowels++;
            }
            if(vowels==0) return false;  // only in  this case, alice will lose , she won't be able to take her first turn even..
             return true;  
            
        }
    };
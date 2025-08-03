//KMP algorithm

class Solution {
public:
    int KMP(string text,string pattern){
         int n=text.size();
         int m=pattern.size();

         //Form LPS array
         vector<int> LPS(m);
         LPS[0]=0;
         int len=0;
         int i=1;
         while(i<m){
             if(pattern[len]==pattern[i]){
                len++;
                LPS[i]=len;
                i++;
             }
             else{
                if(len!=0){
                    len=LPS[len-1];
                }
                else{
                    LPS[i]=0;
                    i++;
                }
             }
         }

         //matching the pattern with the text
         i=0;
         int j=0;
         while(i<n){
             if(pattern[j]==text[i]){
                i++;
                j++;
             }

             if(j==m) return i-j;
             else if(pattern[j]!=text[i]){
                if(j!=0){
                    j=LPS[j-1];
                }
                else{
                    i++;
                }
             }
             
         }

         return -1;
    }
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size()) return -1;
        return KMP(haystack,needle);
    }
};
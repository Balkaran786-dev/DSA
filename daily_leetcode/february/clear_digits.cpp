// we can make use of stack to store the alphabets, while traversing
// o(n) both space and time


// while traversing from bavk, we can use count for numbers as we don't need the value 
// if numbers but we need their frequency.
// o(n) time  o(1) space
class Solution {
    public:
        string clearDigits(string s) {
           int n=s.size();
           int count=0;
           string ans="";
           for(int i=n-1;i>=0;i--){
            int ch=s[i];
            if(isdigit(ch)){
                count++;
            }
            else{
                if(count) count--;
                else{
                    ans.insert(ans.begin(),ch);
                }
            }
           }
           return ans;
        }
    };
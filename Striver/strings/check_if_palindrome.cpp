// my own approach, won't be working if we compare 0 to P , 1 to Q and so on.
// because 0 having lesser ascii value, we will add 32 in it so 48+32=80 -> P , so this
// comparison will give true, which is not acceptable

class Solution {
public:
    bool check(char ch){
        if(ch>=65 && ch<=90) return true;

        if(ch>=97 && ch<=122) return true;

        if(ch>=48 && ch<=57) return true;

        return false;
    }
    bool isPalindrome(string s) {
        int n=s.size();
        int lo=0;
        int hi=n-1;
        bool flag1,flag2;
        char ch1,ch2;
        while(lo<hi){
            ch1=s[lo];
            ch2=s[hi];
            flag1=check(ch1);
            flag2=check(ch2);

            if(flag1 && flag2){
                  if(ch1>ch2 && ch1!=ch2+32 ) return false;  
                  else if(ch1<ch2 && ch2!=ch1+32) return false;  
                  lo++;
                  hi--;
            }
            else if(!flag1){
                lo++;
            }
            else{
                hi--;
            }
        }
        return true;
    }
}; 




// best approach , only convert the uppercase letter.
class Solution {
public:
    bool isAlphaNumeric(char ch) {
        // Check if the character is alphanumeric
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            return true;
        }
        return false;
    }

    char toLowerCase(char ch) {
        // Convert uppercase to lowercase manually
        if (ch >= 'A' && ch <= 'Z') {
            return ch + 32; // 'A' to 'a', 'B' to 'b', etc.
        }
        return ch; // Return as is if not uppercase
    }

    bool isPalindrome(string s) {
        int lo = 0;
        int hi = s.size() - 1;

        while (lo < hi) {
            // Skip non-alphanumeric characters
            while (lo < hi && !isAlphaNumeric(s[lo])) lo++;
            while (lo < hi && !isAlphaNumeric(s[hi])) hi--;

            // Compare characters after converting to lowercase
            if (toLowerCase(s[lo]) != toLowerCase(s[hi])) {
                return false;
            }

            lo++;
            hi--;
        }
        return true;
    }
};

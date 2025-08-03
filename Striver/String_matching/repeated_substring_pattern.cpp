//not by KMP.

class Solution {
public:
    //o(n*sqrt(n)) overall time complexity.
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
       //to optimise , we have started from n/2 , , like take example, aaaaaaaaaaaaaaaaaaa.
       //esme hume append krna jada nhi pada , lekin agr hum 1 se shuru krte, toh jada time lgta.
        for (int l = n / 2; l >= 1; l--) {
            if (n % l == 0) {  //since, a number n can have 2*sqrt(n) divisors, so this will run this much time.
                int times = n / l;  //this many times, this substring needs to be appended

                string pattern = s.substr(0, l);//o(n)
                string newStr = "";

                while (times--) {  //o(n)
                    newStr += pattern;
                }

                if (newStr == s) 
                    return true;
            }
        }

        return false;
    }
};
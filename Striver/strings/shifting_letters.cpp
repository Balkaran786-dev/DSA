// used the concept of suffix sum
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.size();

        int shiftsum=0;
        for(int i=n-1;i>=0;i--){
            shiftsum=(shiftsum+shifts[i])%26;
            s[i]='a'+(s[i]-'a'+shiftsum)%26;
        }
        return s;
    }
};
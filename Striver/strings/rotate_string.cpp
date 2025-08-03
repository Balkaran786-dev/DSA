// approach
// s=abcde goal=cdeab
// s+=s  ->  abcdeabcde
// idx1=0
// idx2=goal.length-1 -> 4
//  abcdeabcde
//  !   !   is substring se goal ko match kro, if matched return ed true otherwise
// idx1++, idx2++,
// firse substring match kro.

class Solution {
public:
    bool rotateString(string s, string goal) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(s.length()!=goal.length()) return false;
        s+=s;
        int idx1=0;
        int idx2=goal.length()-1;
        string str;
        while(idx2!=s.length()){
           str=s.substr(idx1,idx2-idx1+1);
           if(str==goal) return true;
           idx1++;
           idx2++;
        }

        return false;

    }
};
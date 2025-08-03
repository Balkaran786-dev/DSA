//1st solution explained in copy o(n^2) time and o(1) space

/*

main intuition is if we have a substring,
we will not be anyway trying to change the character that has maximum freq in it,
but we will chnage all the characters that are not equal to the characetr that has max freq in it
that means in a substring of length 'L', we need to change -> (L - max_f)...max_f is the maximum freq of a character in that substring

*/

//2nd solu  o(n+n)*26  time
class Solution {
public:
    int characterReplacement(string s, int k) {
        int lo=0,hi=0,max_len=0,max_f=0,n=s.size();
        unordered_map<int,int> mp;

        while(hi<n){
            
            mp[s[hi]-'A']++;
            max_f=max(max_f,mp[s[hi]-'A']);
            while((hi-lo+1)-max_f>k){
                mp[s[lo]-'A']--;
                max_f=0;
                for(int i=0;i<26;i++){
                    max_f=max(max_f,mp[i]);
                }
                lo++;
            }
            if((hi-lo+1)-max_f<=k){
                 max_len=max(hi-lo+1,max_len);
            }
            
            hi+=1;
        }
        return max_len;
    }
};







//most optimised o(n) time  o(26) space
class Solution {
public:
    int characterReplacement(string s, int k) {
        int lo=0,hi=0,max_len=0,max_f=0,n=s.size();
        unordered_map<int,int> mp;
        while(hi<n){
            
            mp[s[hi]-'A']++;
            max_f=max(max_f,mp[s[hi]-'A']);
            if((hi-lo+1)-max_f>k){
                mp[s[lo]-'A']--;
                max_f=0;
                lo++;
            }
            if((hi-lo+1)-max_f<=k){
                 max_len=max(hi-lo+1,max_len);
            }
            
            hi+=1;
        }
        return max_len;
    }
};
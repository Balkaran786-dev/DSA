// o(n) sliding window approach..
// my own approach..here im using erase function which i can avoid like i did in my next example..

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n=s.size();
            int l=0,r=0;
            unordered_map<char,int> mp;  // ele,index
            int length=0;
            while(r<n){
                if(mp.find(s[r])!=mp.end()){
                    int val=mp[s[r]]+1;
                    while(l!=val){
                        mp.erase(s[l]);
                        l++;
                    }
                }
                mp[s[r]]=r;
                length=max(length,r-l+1);
                r++;
            }
            return length;
        }
};


// not using erase function in this,
// while traversing  , if i found a charcter repeating, either it can be in my current substring(i need to move forward my lo) or before anywhere i found it, but it is not in my current substring.
// so, in that case, i can just calculate my length....


class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n=s.size();
            if(n==0 || n==1) return n;
            int lo=0;
            int hi=0;
            unordered_map<char,int> mp; // character,index
    
    
            int length=1;
            mp[s[0]]=0;
            hi+=1;
            while(hi<n){
                 if(mp.find(s[hi])!=mp.end()){
                    int idx=mp[s[hi]];
                    if(idx>=lo){
                      lo=idx+1;
                    }
                    else{
                       length=max(length,hi-lo+1);
                    }
                 }
                 else{
                    length=max(length,hi-lo+1);
                 }
    
                 mp[s[hi]]=hi;
                 hi+=1;
            }
    
            return length;
    
        }
};


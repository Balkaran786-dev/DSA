// used the atleast(k)-atleast(k+1) vali approach...
//APPROACH 1: we can't go by exactly k consonants bcz then we will shrink the window from left side and will loose some of the vowels from left side.
//similarly we can't go by at most k bcz then after getting more than k consonants we will shrink the window from left side and will loose on some vowels.
// Counting "at most K" doesn't guarantee that all vowels appear at least once — you might accidentally include incomplete or invalid substrings.
// Additionally, "at most K" logic cannot properly isolate conditions where consonants appear in exact counts when additional constraints (like the presence of all vowels) are required.
//  (like "at least K consonants and all vowels"), valid substrings may contain more than K consonants — so using "at most" risks missing valid answers or including invalid substrings.


class Solution {
    public:
        long long atLeast(string word,int k,int n){
            int l=0,r=0;
            long long cnt=0;
            unordered_map<char,int> mp;
            mp['a']=1;
            mp['e']=1;
            mp['i']=1;
            mp['o']=1;
            mp['u']=1;
            int cnt1=0,cnt2=0;
    
            while(r<n){
                 if(mp.find(word[r])==mp.end()){
                    cnt2++;
                 }
                 else{
                    mp[word[r]]--;
                    if(mp[word[r]]==0) cnt1++;
                 }
            
                 while(l<=r && cnt1==5 && cnt2>=k){
                    cnt+=(n-r);
                    if(mp.find(word[l])==mp.end()){
                      cnt2--;
                    }
                    else{
                        mp[word[l]]++;
                        if(mp[word[l]]==1) cnt1--;
                    }
                    l++;
                 }
                 r++;
            }
            return cnt;
        }
    
        long long countOfSubstrings(string word, int k) {
            int n=word.size();
    
            return atLeast(word,k,n)-atLeast(word,k+1,n);
        }

};

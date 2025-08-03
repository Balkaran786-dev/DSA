class Solution {
    public:
        int maxConsecutiveAnswers(string s, int k) {
            int n=s.size();
            int l=0,r=0,max_len=0,max_f=0;
            unordered_map<char,int> mp;
            while(r<n){
                mp[s[r]]++;
                max_f=max(max_f,mp[s[r]]);
                if((r-l+1)-max_f>k){
                     mp[s[l]]--;
                     max_f=0;
                     for(auto ele:mp){
                        max_f=max(max_f,ele.second);
                     }
                     l++;
                }
                if((r-l+1)-max_f<=k){
                    max_len=max(max_len,r-l+1);
                }
                r++;
            }
            return max_len;
        }
    
    };
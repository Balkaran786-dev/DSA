class Solution {
    public:
        string lastNonEmptyString(string s) {
            vector<int> freq(26,0);
            int n=s.size();
            int max_freq=0;
            for(int i=0;i<n;i++){
                freq[s[i]-'a']++;
                if(freq[s[i]-'a']>max_freq){
                    max_freq=freq[s[i]-'a'];
                }
            }
            
            string ans="";
            for(int i=n-1;i>=0;i--){
                if(freq[s[i]-'a']==max_freq){
                    ans.insert(ans.begin(),s[i]);
                    freq[s[i]-'a']--;
                }
            }
            return ans;
        }
    };
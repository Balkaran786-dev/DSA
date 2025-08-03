class Solution {
    public:
        int minimumLength(string s) {
            unordered_map<char,int> mp;
            int n=s.size();
            for(int i=0;i<n;i++){
                mp[s[i]]++;
            }
            
            int cnt=0;
            for(auto ele:mp){
                int freq=ele.second;
                if(freq>2){
                    if(freq%2==0){
                       cnt+=freq-2;
                    }
                    else{
                        cnt+=freq-1;
                    }
                }
            }
            return n-cnt;
        }
    };
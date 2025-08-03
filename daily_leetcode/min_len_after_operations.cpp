//insights:-
// freq of character is what imp in this ques
// if freq is >2, then only operation can be performed on it
// and uske aage if freq is odd like 7, we can remove all ele except one 
// and if freq is even like 6, we can remove all excpet last two.

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
// very similar to sliding window approach of finding at most k  distinct subarrays vala question
class Solution {
  public:
    int CountSubstrK(string &s,int k,int n){ //calculate subtsrings with at most k distinct characters
        int l=0,r=0;
        unordered_map<char,int> mp;
        int ans=0;
        
        while(r<n){
            mp[s[r]]++;
            while(mp.size()>k){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    int countSubstr(string& s, int k) {
        // code here.
        int n=s.size();
        return CountSubstrK(s,k,n)-CountSubstrK(s,k-1,n);
 }
};
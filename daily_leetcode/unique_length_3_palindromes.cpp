
class Solution {
public:

    int countPalindromicSubsequence(string s) {
        int n=s.size();
        unordered_map<int,pair<int,int>> mp;
        for(char ch='a';ch<='z';ch++){
            mp[ch]={-1,-1};
        }

        for(int i=0;i<n;i++){
            if(mp[s[i]].first==-1){
                mp[s[i]].first=i;
            }
        }

        for(int i=n-1;i>=0;i--){
            if(mp[s[i]].second==-1){
                mp[s[i]].second=i;
            }
        }   
        
        int ans=0;

        for(auto ele:mp){

            int start=ele.second.first;
            int end=ele.second.second;

            if(start==-1) continue;  //not presnt

            if(end-start<2) continue;  //not having any character between them

            unordered_set<char> st;
            for(int i=start+1;i<end;i++){
                st.insert(s[i]);
            }

            ans+=st.size();
        }
        return ans;
    }
};
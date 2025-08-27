//Naive solution
// actually generating all substrings
//explained in copy...


class Solution {
public:
    string minWindow(string s, string t) {
        int min_len=INT_MAX;
        int start_idx=-1;
        int n=s.size(),m=t.size();
        for(int i=0;i<n;i++){

            int cnt=0;
            unordered_map<char,int> mp;

            for(int j=0;j<m;j++){
                mp[t[j]]++;
            }

            int k;
            for(k=i;k<n;k++){
                if(mp[s[k]]>0) cnt++;
                mp[s[k]]--;

                if(cnt==m){
                    if(k-i+1<min_len){
                       min_len=k-i+1;
                       start_idx=i;
                    }
                    break;
                }
            } 
        }
        if(start_idx==-1) {
            return "";
        }
        return s.substr(start_idx,min_len);
    }
};



//2nd solution:-
class Solution {
public:
    string minWindow(string s, string t) {
        
        int min_len=INT_MAX;
        int start_idx=-1;
        int n=s.size(),m=t.size();
        if(m>n) return "";
        int cnt=0;  //how many characters of t are present in the current substring..
        int lo=0,hi=0;

        unordered_map<char,int> mp;
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }

        while(hi<n){
            if(mp[s[hi]]>0) cnt++;
            mp[s[hi]]--;
            while(cnt==m){
                if(hi-lo+1<min_len){
                    min_len=hi-lo+1;
                    start_idx=lo;
                }

                if(mp[s[lo]]==0) cnt--;
                mp[s[lo]]++;
                lo++;
            }
            hi+=1;
        }

        if(start_idx==-1) return "";
        return s.substr(start_idx,min_len);
    }
};
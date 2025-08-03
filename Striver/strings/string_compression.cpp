// 3 pointer approach
class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        if(n==1) return 1;

        int start=0;
        int check=1;
        int place=0;

        while(start<n){
            int cnt=1;
            while(check<n && chars[start]==chars[check]){
                check++;
                cnt++;
            }
            
            
            chars[place++]=chars[start];
            if(cnt!=1){
                string count=to_string(cnt);
                int sz=count.size();
                int idx=0;
               while(idx<sz){
                chars[place++]=count[idx++];
               }
            }
            
            start=check;
            check=start+1;
        }
        return place;
    }
};
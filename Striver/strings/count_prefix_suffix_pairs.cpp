// easy one.
class Solution {
public:
    bool is_prefix_suffix(string s1,string s2){
        int n1=s1.size();
        int n2=s2.size();
        if(s2.substr(0,n1)==s1 && s2.substr(n2-n1)==s1) return true;

        return false;

    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int cnt=0;

        for(int i=0;i<n;i++){
            string str=words[i];
            for(int j=i+1;j<n;j++){
                if( words[j].size()>=str.size() && is_prefix_suffix(str,words[j])) cnt++;
            }
        }

        return cnt;
    }
};
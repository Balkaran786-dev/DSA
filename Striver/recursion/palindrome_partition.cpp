//main motive is to make partitions,
// during recursion, whenever im partition, im just checking whether the part before 
// partition is a plaindrome or not, baad vale ke liye toh aap recursion call kroge hi, toh uski
// tension lene ke liye rehne do, you just check ki the part before partion is palindrome or not,
// if yes, include that substring in temp and call your recursion for ahead part,


// tree diagram given in copy..
// time - o(n*2^n) 2^n -> beacuse every time im deciding whether to cut or not cut , n->to check if it is palindrome or not.
// space - o(n*2^n) -> for result storage and o(n) -> recursion stack

class Solution {
public:
    bool is_palindrome(string s,int start,int end){
        while(start<end && start!=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void get_all_partitions(string s,int idx,int n,vector<string> temp,vector<vector<string>>&ans){
        if(idx==n){
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<n;i++){
            if(is_palindrome(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                get_all_partitions(s,i+1,n,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int idx=0;
        int n=s.size();
        vector<vector<string>> ans;
        vector<string> temp;
        get_all_partitions(s,idx,n,temp,ans);
        return ans;
    }
};
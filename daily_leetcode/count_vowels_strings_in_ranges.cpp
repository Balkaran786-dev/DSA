// simple used prefix approach in a self made vector where 1 means it is having vowel in start and end and 0 means
// it is not having vowel in the start and end.

class Solution {
public:
    bool checker(string &str){
        int n=str.size();
        if((str[0]=='a' ||str[0]=='e' ||str[0]=='i' ||str[0]=='o' ||str[0]=='u') && (str[n-1]=='a' ||str[n-1]=='e' ||str[n-1]=='i' ||str[n-1]=='o' ||str[n-1]=='u')){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> vec(n);
        if(checker(words[0])){
            vec[0]=1;
        }
        else{
            vec[0]=0;
        }

        for(int i=1;i<n;i++){
            if(checker(words[i])){
                vec[i]=vec[i-1]+1;
            }
            else{
                vec[i]=vec[i-1]+0;
            }
        }
        
        int sz=queries.size();
        vector<int> ans(sz);
        for(int i=0;i<sz;i++){
            if(queries[i][0]!=0){
                ans[i]=vec[queries[i][1]]-vec[queries[i][0]-1];
            }
            else{
                ans[i]=vec[queries[i][1]];
            }
        }
        return ans;
    }
};
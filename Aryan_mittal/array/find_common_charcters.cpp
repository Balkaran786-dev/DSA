// ek character ki jo min freq hogi sabhi words mein , vahi sabme common hoga....
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<int> first_word(26,0);
        int sz1=words[0].size();
        for(int i=0;i<sz1;i++){
            first_word[words[0][i]-'a']++;
        }

        for(int i=1;i<n;i++){
            vector<int> temp(26,0);
            int sz=words[i].size();
            for(int j=0;j<sz;j++){
                temp[words[i][j]-'a']++;
            }

            for(int i=0;i<26;i++){
                first_word[i]=min(first_word[i],temp[i]);
            }
        }
        vector<string> ans;
        for(int i=0;i<26;i++){
            
            while(first_word[i]!=0){
                string str="";
                str+=(i+'a');
                ans.push_back(str);
                first_word[i]--;
            }
        }
        return ans;
    }
};
// brute force is all we can do in this question
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n=words.size();
        for(int i=0;i<n;i++){
            string str=words[i];
            for(int j=0;j<n;j++){
                if(i!=j && words[j].find(str)!=string::npos){
                    ans.push_back(str);
                    break;
                }
            }
        }
        return ans;
    }
};

// either we can use KMP...

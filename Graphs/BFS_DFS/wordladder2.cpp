class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n=beginWord.size();
        
        //datastructures needed...
        unordered_set<string> st;
        queue<vector<string>> qu;
        vector<vector<string>> result;
        vector<string> ans;

        for(auto ele:wordList) st.insert(ele);

        ans.push_back(beginWord);
        qu.push(ans);
        while(!qu.empty()){
            int sz=qu.size();
            vector<string> tempo;
            while(sz--){
               vector<string> vec=qu.front();
               qu.pop();

               string str=vec.back();

               if(str==endWord){
                if(!result.empty() && result[0].size()<vec.size()) return result;
                result.push_back(vec);
                continue;
               }

               for(int i=0;i<n;i++){
                string temp=str;
                for(char ch='a';ch<='z';ch++){
                    temp[i]=ch;
                    if(str[i]!=ch && st.count(temp)){
                        vec.push_back(temp);
                        qu.push(vec);
                        tempo.push_back(temp);
                        vec.pop_back();
                    }
                }
              }

            }
            for(auto ele:tempo) st.erase(ele);
        }
        return result;
    }
};
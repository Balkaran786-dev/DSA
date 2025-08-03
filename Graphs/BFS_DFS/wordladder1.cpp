class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=beginWord.size();
        unordered_set<string> st;
        for(auto ele:wordList) st.insert(ele);
        queue<string> qu;
        qu.push(beginWord);
        int level=1;
        while(!qu.empty()){
            int sz=qu.size();
            while(sz--){
              string str=qu.front();
              qu.pop();
              if(str==endWord) return level;
              for(int i=0;i<n;i++){
                string temp=str;
                for(char ch='a';ch<='z';ch++){
                    temp[i]=ch;
                    if(str[i]!=ch && st.count(temp)){
                        qu.push(temp);
                        st.erase(temp);
                    }
                }
              }
            }
            level++;
        }
        return 0;
    }
};
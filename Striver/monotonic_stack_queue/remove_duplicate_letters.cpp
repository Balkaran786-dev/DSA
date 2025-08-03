class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        stack<char> st;
        unordered_map<char,int> mp;
        unordered_set<char> visited;
        for(auto ele:s){
              mp[ele]+=1;
        }
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(st.empty()){
                st.push(ch);
                visited.insert(ch);
            }
            else{
                if(visited.count(ch)){
                     mp[ch]--;
                    continue;
                }
                else{
                        while(!st.empty() && st.top()>ch && mp[st.top()]!=0){
                            visited.erase(st.top());
                            st.pop();
                        }
                        st.push(ch);
                        visited.insert(ch);
                }
                
            }
            mp[ch]--;
        }
        string str="";
        while(!st.empty()){
            str.push_back(st.top()); st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
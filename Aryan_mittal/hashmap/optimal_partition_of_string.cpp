/*
as soon as i get a character that i have got in my current substring, break that ongoing
substring and start a new substring*/
class Solution {
    public:
        int partitionString(string s) {
            int n=s.size();
            unordered_set<int> st;
            int partitions=0;
            for(int i=0;i<n;i++){
                char ch=s[i];
                if(st.count(ch)==0){
                    st.insert(ch);
                }
                else{
                    st.clear();
                    st.insert(ch);
                    partitions++;
                }
            }
            return partitions+1;
        }
    };
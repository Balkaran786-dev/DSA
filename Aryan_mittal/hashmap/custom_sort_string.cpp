class Solution {
    public:
        string customSortString(string order, string s) {
            int n1=order.size();
            int n2=s.size();
            
            string ans="";
            vector<int> freq(26,-1);
            for(int i=0;i<n1;i++){
                freq[order[i]-'a']=0;
            }
    
            for(int i=0;i<n2;i++){
                char ch=s[i];
                if(freq[ch-'a']==-1){
                    ans.push_back(ch);
                }
                else{
                    freq[ch-'a']++;
                }
            }
    
            for(int i=0;i<n1;i++){
                int val=freq[order[i]-'a'];
                while(val>0){
                   ans.push_back(order[i]);
                   val--; 
                }
            }
            return ans;
        }
    };
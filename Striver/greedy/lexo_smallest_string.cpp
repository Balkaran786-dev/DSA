//3170.

class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        vector<stack<int>> st(26);
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch!='*'){
                st[ch-'a'].push(i);
            }
            else{
                int a=-1;
                for(int i=0;i<=25;i++){
                   if(!st[i].empty()){
                    a=i;
                    break;
                   }
                }
                st[a].pop();
            }
        }
       string res="";
       while(true){
          int idx=-1;
          int a=-1;
          for(int i=0;i<26;i++){
             if(!st[i].empty() && idx<st[i].top()){
                idx=st[i].top();
                a=i;
             }
          }
          if(idx==-1) break;
          res.push_back('a'+a);
          st[a].pop();
       }
        reverse(res.begin(),res.end());
        return res;

    }
};
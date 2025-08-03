class Solution {
public:
    bool get_smallestNumber(int index,string &ans,string &pattern,int n,vector<int> &visited){
        if(index==n){
            return true;
        }

        if(pattern[index]=='I'){
            int val=ans.back()-'0';
            for(int i=val+1;i<=9;i++){
                if(visited[i]==0){
                    visited[i]=1;
                    ans.push_back(i+'0');
                    if(get_smallestNumber(index+1,ans,pattern,n,visited)) return true;
                    ans.pop_back();
                    visited[i]=0;
                }
            }
        }
        else{
            int val=ans.back()-'0';
            for(int i=val-1;i>=1;i--){
                if(visited[i]==0){
                    visited[i]=1;
                    ans.push_back(i+'0');
                    if(get_smallestNumber(index+1,ans,pattern,n,visited)) return true;
                    ans.pop_back();
                    visited[i]=0;
                }
            }
        }
        return false;
    }
    string smallestNumber(string pattern) {
        int n=pattern.size();
        string ans="";
        vector<int> visited(10,0);
        for(int i=1;i<=9;i++){
             ans.push_back(i+'0');
             visited[i]=1;
             if(get_smallestNumber(0,ans,pattern,n,visited)) return ans;
             ans.pop_back();
             visited[i]=0;
        }
        return ans;
    }
};
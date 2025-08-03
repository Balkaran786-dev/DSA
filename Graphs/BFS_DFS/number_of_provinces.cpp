class Solution {
public:
    void bfs(unordered_set<int> &st,vector<vector<int>> &isConnected){
           queue<int> qu;
           auto itr=st.begin();
           qu.push(*itr);
           while(!qu.empty()){
            int cell=qu.front();
            qu.pop();
            st.erase(cell);
            for(int j=0;j<isConnected[0].size();j++){
                if(j!=cell-1 && isConnected[cell-1][j]==1 && st.count(j+1)){
                    qu.push(j+1);
                    st.erase(j+1);
                }
            }
           }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        ios_base::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);

        unordered_set<int> st;
        for(int i=0;i<isConnected.size();i++){
            st.insert(i+1);
        }
        int count=0;
        while(!st.empty()){
            count++;
            bfs(st,isConnected);
        }
        return count;
    }
};




//more simple
class Solution {
public:
    void dfs(int i,vector<vector<int>>& isConnected,int n){
        isConnected[i][i]=-1;
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && isConnected[j][j]==1){
                dfs(j,isConnected,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(isConnected[i][i]==1){
                cnt++;
                dfs(i,isConnected,n);
            }
        }
        return cnt;
    }
};
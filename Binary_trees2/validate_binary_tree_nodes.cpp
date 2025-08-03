

class Solution {
public:
    bool dfs(vector<bool> &visited,int i,unordered_map<int,vector<int>> &adj){
        visited[i]=true;
        for(auto ele:adj[i]){
            if(visited[ele]) return false;
            dfs(visited,ele,adj);
        }
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,vector<int>> adj;
        vector<int> parent(n,0);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1){
                parent[leftChild[i]]++;
                adj[i].push_back(leftChild[i]);
            }
            if(rightChild[i]!=-1){
                parent[rightChild[i]]++;
                adj[i].push_back(rightChild[i]);
            }
        }

        int cnt=0;
        int root=-1;
        for(int i=0;i<n;i++){
            if(parent[i]==0){
                cnt++;
                root=i;
            }
            else if(parent[i]>1) return false;
        }
         
        if(cnt>1 || cnt==0) return false;

        vector<bool> visited(n,false);
        
        bool res = dfs(visited,root,adj);
        if(!res) return false;
        for(int i=0;i<n;i++){
            if(visited[i]==false) return false;
        }

        return true;
    }
};
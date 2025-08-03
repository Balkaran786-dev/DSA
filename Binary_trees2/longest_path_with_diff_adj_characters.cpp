class Solution {
public:
    pair<int,char> fun(int curr,int &maxi,vector<vector<int>> &adj,string &s){
        
        if(adj[curr].size()==0){
            return {1,s[curr]};
        }

        vector<pair<int,char>> vec;
        for(auto child:adj[curr]){
           vec.push_back(fun(child,maxi,adj,s));
        }
        
        int first_max=0,second_max=0;
    
        for(int i=0;i<vec.size();i++){
            if(vec[i].second!=s[curr] && vec[i].first>first_max){
                second_max=first_max;
                first_max=vec[i].first;
            }
            else if(vec[i].second!=s[curr] && vec[i].first>second_max){
                second_max=vec[i].first;
            }
        }
        maxi=max(maxi,first_max+second_max+1);
        return {first_max+1,s[curr]};
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        int maxi=1;
        int root=0;
        fun(root,maxi,adj,s);
        return maxi;
    }
};
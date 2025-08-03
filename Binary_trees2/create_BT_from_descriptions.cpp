
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& vec) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> st;
        int n=vec.size();
        for(int i=0;i<n;i++){
            int par=vec[i][0],child=vec[i][1],is_left=vec[i][2];
            st.insert(child);
            if(mp.find(par)==mp.end() && mp.find(child)==mp.end()){
                TreeNode* node1 = new TreeNode(par);
                TreeNode* node2 = new TreeNode(child);
                if(is_left==1){
                    node1->left=node2;
                }
                else node1->right=node2;
                mp[par]=node1;
                mp[child]=node2;
            }
            else if(mp.find(par)!=mp.end() && mp.find(child)!=mp.end()){
                if(is_left==1){
                    mp[par]->left=mp[child];
                }
                else mp[par]->right=mp[child];
            }
            else if(mp.find(par)==mp.end()){
                TreeNode* node = new TreeNode(par);
                if(is_left==1){
                    node->left=mp[child];
                }
                else node->right=mp[child];
                mp[par]=node;
            }
            else if(mp.find(child)==mp.end()){
                TreeNode* node = new TreeNode(child);
                if(is_left==1){
                    mp[par]->left=node;
                }
                else mp[par]->right=node;
                mp[child]=node;
            }
        }

        for(auto ele:mp){
            if(st.count(ele.first)==0) return ele.second;
        }
        return NULL;
    }
};
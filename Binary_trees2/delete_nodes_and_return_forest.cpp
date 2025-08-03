
class Solution {
public:
    TreeNode* fun(TreeNode* root,bool put,unordered_set<int> &st,vector<TreeNode*> &result){
        if(!root) return NULL;

        bool present=st.count(root->val)==1;
        if(!present && put){
            result.push_back(root);
            put=false;
        }
        else if(present) put = true;
        
        root->left=fun(root->left,put,st,result);
        root->right=fun(root->right,put,st,result);

        if(present) return NULL;
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st;
        for(int i=0;i<to_delete.size();i++){
            st.insert(to_delete[i]);
        }
        
        vector<TreeNode*> result;
        fun(root,true,st,result);
        return result;
    }
};
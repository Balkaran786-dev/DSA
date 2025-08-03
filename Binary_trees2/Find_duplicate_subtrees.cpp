//it actually like we are serializing and check each subtring as well in recursion only...

class Solution {
public:
    string fun(TreeNode* root,vector<TreeNode*> &result,unordered_map<string,int>& mp){
        if(root==NULL) return "N";

        string s= to_string(root->val)+","+fun(root->left,result,mp)+","+fun(root->right,result,mp);
        if(mp[s]==1){
            result.push_back(root);
        }
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> mp;
        vector<TreeNode*> result;
        fun(root,result,mp);
        return result;
    }
};
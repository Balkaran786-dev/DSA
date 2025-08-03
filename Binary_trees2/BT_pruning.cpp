
class Solution {
public:
    TreeNode* fun(TreeNode* root){
        if(!root) return NULL;

        root->left=fun(root->left);
        root->right=fun(root->right);

        if(root->val==0 && !root->left && !root->right) return NULL;
        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return fun(root);
    }
};
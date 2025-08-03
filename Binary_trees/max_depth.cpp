class Solution {
public:
    int get_depth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        else if(root->left==NULL && root->right==NULL){
            return 1;
        }
        return 1+max(get_depth(root->left),get_depth(root->right));
    }
    int maxDepth(TreeNode* root) {
        return get_depth(root);
    }
};
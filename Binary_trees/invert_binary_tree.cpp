class Solution {
public:
    void invert(TreeNode* root){
        if(!root) return;

        if(!root->left && !root->right) return;

        invert(root->left);
        invert(root->right);
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};


//neeche se jo node hai uake left child ko right and
//right ko left banado,essa har ek non leaf node ke liye
//krdo...
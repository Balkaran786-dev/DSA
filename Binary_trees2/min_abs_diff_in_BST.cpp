
class Solution {
public:
    int mini=INT_MAX;
    void fun(TreeNode* root,int &prev){
        if(!root) return;

        fun(root->left,prev);
        if(prev!=-1){
            mini=min(mini,abs(root->val-prev));
        } 
        prev=root->val;
        fun(root->right,prev);
    }
    int getMinimumDifference(TreeNode* root) {
        int prev=-1;
        fun(root,prev);
        return mini;
    }
};
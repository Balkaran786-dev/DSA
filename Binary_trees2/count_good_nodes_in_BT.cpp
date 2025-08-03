
class Solution {
public:
    void fun(TreeNode* root,int maxi,int &ans){
        if(root==NULL) return;

        if(maxi<=root->val) ans++;
        maxi=max(maxi,root->val);
        fun(root->left,maxi,ans);
        fun(root->right,maxi,ans);
    }
    int goodNodes(TreeNode* root) {
        int maxi=INT_MIN;
        int cnt=0;
        fun(root,maxi,cnt);
        return cnt;
    }
};
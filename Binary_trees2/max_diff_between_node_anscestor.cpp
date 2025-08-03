class Solution {
public:
    void fun(TreeNode* root,int mini,int maxi,int &ans){
        if(root==NULL) return;

         mini=min(mini,root->val);
         maxi=max(maxi,root->val);
         if(!root->left && !root->right){
            ans=max(ans,maxi-mini);
            return;
         }

         fun(root->left,mini,maxi,ans);
         fun(root->right,mini,maxi,ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        int mini=INT_MAX,maxi=INT_MIN;
        int ans=INT_MIN;
        fun(root,mini,maxi,ans);
        return ans;
    }
};
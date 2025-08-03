
class Solution {
public:
    TreeNode* fun(TreeNode* root, int &target){
         if(root==NULL) return NULL;

         if(!root->left && !root->right){
            if(root->val==target) return NULL;
            else return root;
         }

         root->left=fun(root->left,target);
         root->right=fun(root->right,target);

         if(!root->left && !root->right && root->val==target)return NULL;
          return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return fun(root,target);
    }
};

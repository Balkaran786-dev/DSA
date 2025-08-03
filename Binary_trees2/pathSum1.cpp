//here we need to just return whether a path is presnt from root to any leaf node
//whose sum of the nodes is equal to target.

class Solution {
public:
    bool if_path_present(TreeNode* root,int sum,int targetSum){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
           if(sum+root->val==targetSum){
                return true;
           }
           else{
               return false;
           }  
        }

        bool res1=if_path_present(root->left,sum+root->val,targetSum);
        if(res1){
            return true;
        }
        bool res2=if_path_present(root->right,sum+root->val,targetSum);
        if(res2){
            return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return if_path_present(root,0,targetSum);
    }
};
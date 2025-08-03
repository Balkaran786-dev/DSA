//3rd solution as per written in copy
class Solution {   //o(n) - time complexity   o(h)-space,where h is the height of tree that can be N in worst case if our tree is skewed.
public:
    bool if_BST(TreeNode* &root,long long min_val,long long max_val){
          if(root==NULL) return true;

          if(root->val<=min_val || root->val>=max_val){
              return false;
          }
          
          bool res1=if_BST(root->left,min_val,root->val);
          if(!res1) return false;
          bool res2=if_BST(root->right,root->val,max_val);
          if(!res2) return false;
          return true;

    }
    bool isValidBST(TreeNode* root) {
        return if_BST(root,LLONG_MIN,LLONG_MAX);
    }
};


//2nd solution as per written in copy
class Solution {
public:
    bool if_BST(TreeNode* &root,TreeNode* &prev){
          if(root==NULL) return true;

          bool res1=if_BST(root->left,prev);
          if(!res1) return false;

          if(prev!=NULL && root->val<=prev->val) return false;
          prev=root;

          bool res2=if_BST(root->right,prev);
          if(!res2) return false;

          return true;

    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev=NULL;
        return if_BST(root,prev);
    }
};


//1st solution is easy.
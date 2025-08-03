class Solution {
public:
    void inorder_traverse(TreeNode* root,vector<TreeNode*> &inorder){
        if(root==NULL)return;

        inorder_traverse(root->left,inorder);
        inorder.push_back(root);
        inorder_traverse(root->right,inorder);
    }
    
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorder;
        inorder_traverse(root,inorder);
        TreeNode* first_swapped_node=NULL;
        TreeNode* second_swapped_node=NULL;
        for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i]->val>inorder[i+1]->val){
                if(first_swapped_node==NULL) first_swapped_node=inorder[i];
                second_swapped_node=inorder[i+1];
            }
        }
        
        int temp=first_swapped_node->val;
        first_swapped_node->val=second_swapped_node->val;
        second_swapped_node->val=temp;
    }
};
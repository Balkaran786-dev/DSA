class Solution {
public:
    TreeNode* get_BST(vector<int>& preorder,int a1,int a2){
        if(a1==a2){   //leaf node
            TreeNode* node=new TreeNode(preorder[a1]);
            return node;
        }
        if(a1>a2) return NULL;  // when tree is empty or may be,no ele is present in this part of tree
        
        TreeNode* curr=new TreeNode(preorder[a1]);
        int i;
        for(i=a1;i<=a2;i++){
            if(preorder[i]>preorder[a1]) break;  //found the first greater ele from the root node
        }

        curr->left=get_BST(preorder,a1+1,i-1);
        if(i>a2) curr->right=NULL;  //right subtree khali hi hoga since no geater ele is found
        else curr->right=get_BST(preorder,i,a2);

        return curr;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return get_BST(preorder,0,preorder.size()-1);
    }
};
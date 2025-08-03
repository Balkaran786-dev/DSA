void fun(TreeNode<int>* &root,TreeNode<int>* &new_root,TreeNode<int>* &new_node){
     if(root->left==NULL){
         new_root=root;
         new_node=root;
         return;
     }

     fun(root->left,new_root,new_node);
     new_node->left=root->right;
     new_node->right=root;
     new_node=new_node->right;

     root->left = NULL;  // Break old links
     root->right = NULL;
}
TreeNode<int>* flipTree(TreeNode<int> *root){
	// Write your code here.
    TreeNode<int>* new_root=NULL;
    TreeNode<int>* new_node=NULL;
    fun(root,new_root,new_node);
    return new_root;
}
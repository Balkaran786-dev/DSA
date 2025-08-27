bool isLeaf(TreeNode<int>* root) {
        return !root->left && !root->right;
    }

void addLeft(TreeNode<int> *root,vector<int>& ans){
    if(!root)return;
    if(!isLeaf(root)){
        ans.push_back(root->data);
    }
    if(root->left){
        addLeft(root->left,ans);
    }
    else if(root->right){
        addLeft(root->right,ans);
    }
}
void addLeaf(TreeNode<int> *root,vector<int>& ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
    }
    if(root->left)addLeaf(root->left,ans);
    if(root->right)addLeaf(root->right,ans);
}
void addRight(TreeNode<int> *root,vector<int>& temp){\
    if(!root)return;
    if(!isLeaf(root)){
        temp.push_back(root->data);
    }
    if(root->right){
        addRight(root->right,temp);
    }
    else if(root->left){
        addRight(root->left,temp);
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int> ans;
    if(!isLeaf(root))ans.push_back(root->data);
    TreeNode<int> *curr=root;
    root=root->left;
    addLeft(root,ans);
    root=curr;
    addLeaf(root,ans);
    vector<int> temp;
    root=root->right;
    addRight(root,temp);
    int n=temp.size();
    for(int i=n-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
    return ans;
}
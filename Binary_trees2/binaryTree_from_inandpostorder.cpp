class Solution {
public:
    unordered_map<int,int> mp;
    TreeNode* get_tree(vector<int>& inorder, vector<int>& postorder,int instart,int inend,int poststart,int postend){
        if(instart>inend || poststart>postend){
            return NULL;
        }
        
        int curr_node_val=postorder[postend];
        TreeNode* curr=new TreeNode(curr_node_val);
        int root_idx=mp[curr_node_val];
        int left_subtree_ele=root_idx-instart;
        curr->left=get_tree(inorder,postorder,instart,instart+left_subtree_ele-1,poststart,poststart+left_subtree_ele-1);
        curr->right=get_tree(inorder,postorder,root_idx+1,inend,poststart+left_subtree_ele,postend-1);
        return curr;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=get_tree(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
        return root;
    }
};
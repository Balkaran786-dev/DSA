class BSTIterator {   //o(1) avg time complexity o(h) space complexity

    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        while(root){
            st.push(root);
            root=root->left;
        }
    }

    int next() {
        TreeNode* curr=st.top();
        st.pop();
        TreeNode* left_part=curr->right;
        while(left_part){
            st.push(left_part);
            left_part=left_part->left;
        }
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};








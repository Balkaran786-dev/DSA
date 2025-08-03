
class FindElements {
public:
    unordered_set<int> st;
    void recover_BT(TreeNode* &root,int value){
        if(root==NULL) return;

        root->val=value;
        st.insert(value);
        recover_BT(root->left,value*2+1);
        recover_BT(root->right,value*2+2);
    }
    FindElements(TreeNode* root) {
        st.clear();
        recover_BT(root,0);
    }
    
    bool find(int target) {
        if(st.find(target)==st.end()) return false;
        return true;
    }
};

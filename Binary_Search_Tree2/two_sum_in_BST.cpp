class Solution {
    public:
        bool if_present(TreeNode* &root,int k,unordered_set<int> &st){
            if(!root) return false;
    
            if(st.count(k-root->val)) return true;
    
            st.insert(root->val);
            bool res1=if_present(root->left,k,st);
            if(res1) return true;
            bool res2=if_present(root->right,k,st);
            if(res2) return true;
            return false;
        }
        bool findTarget(TreeNode* root, int k) {
            unordered_set<int> st;
            return if_present(root,k,st);
        }
};



// with help of BST iterator question..
// like we used to sort the array and put two pointer on two ends and then form the pair,
// like that, we will keep one iterator on smallest ele and one on the largest ele, basically on two extremas 
// of inorder traversals, 
// agr sum kam goga , toh next next jate rhenge.
// agr sum jada hoga, to before before jate rhenge.

class BSTIterator {
    public:
        stack<TreeNode*> st;
        bool reverse;  //true->next  false->before
    
        BSTIterator(TreeNode* root,bool is_reverse) {
            reverse=is_reverse;
            while(root){
                st.push(root);
                if(reverse) root=root->left;
                else root=root->right;
            }
        }

        int next() {
            TreeNode* curr=st.top();
            st.pop();
            TreeNode* to_put;
            if(reverse) to_put=curr->right;
            else to_put=curr->left;
    
            while(to_put){
                st.push(to_put);
                if(reverse) to_put=to_put->left;
                else to_put=to_put->right;
            }
            return curr->val;
        }
        
        bool has() {
            return !st.empty();
        }
    };

    // time would be same as o(n) as our previous approach, but space will be o(h),....

    class Solution {
    public:
        bool findTarget(TreeNode* root, int k) {
           BSTIterator b1(root,true);
           BSTIterator b2(root,false);
           int l=b1.next();
           int r=b2.next();
    
           while(l!=r){
             if(l+r==k) return true;
             else if(l+r<k){
                if(b1.has()){
                    l=b1.next();
                }
                else return false;
             }
             else{
                if(b2.has()){
                    r=b2.next();
                }
                else return false;
             }
           }
           return false;
        }
};

//iterative approach
// instead of taking a stack, you can store the elements at the same level in a vector 
// and then check if it is palindrome or not.

class Solution {
public:
    bool if_mirror_img(stack<int> &st){
        int sz=st.size();
        stack<int> temp;
        int i=0;
        while(i!=sz/2){
            temp.push(st.top());
            st.pop();
            i++;
        }
        while(!temp.empty()){
            if(temp.top()!=st.top()) return false;
            st.pop();
            temp.pop();
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {  
        if(!root->left && !root->right) return true;

        queue<TreeNode*> qu;
        qu.push(root);
        int p=1;
        stack<int> st;
        while(!qu.empty()){
            int nodes_at_same_level=p;
            while(nodes_at_same_level--){
                TreeNode* curr=qu.front();
                qu.pop();
                if(curr->left){
                    st.push(curr->left->val);
                    qu.push(curr->left);
                }
                else{
                    st.push(-101);
                }
                if(curr->right){
                    st.push(curr->right->val);
                    qu.push(curr->right);
                }
                else{
                    st.push(-101);
                }
            }
            p=qu.size();
            if(!if_mirror_img(st)) return false;
        }
        return true;
    }
};


//recursive approach

class Solution {
public:
    bool is_mirror(TreeNode* l1,TreeNode* l2){
        if(!l1 && !l2) return true;  //both null, that is acceptable as symmetric,

        if(!l1 || !l2) return false; //one of the child is absent,then it is not symmetric

        return l1->val==l2->val && is_mirror(l1->left,l2->right) && is_mirror(l1->right,l2->left);
        //     check their value is same     check for outer two child         check for their innser two child
    }
    bool isSymmetric(TreeNode* root) {

        return is_mirror(root->left,root->right);
    }
};
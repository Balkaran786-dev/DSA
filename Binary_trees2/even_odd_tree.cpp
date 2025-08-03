
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        int level=0;
        while(!qu.empty()){
            int sz=qu.size();
            int prev=(level%2==0?INT_MIN:INT_MAX);
            bool even_level=level%2==0;
            while(sz--){
                TreeNode* curr = qu.front(); qu.pop();
                int value=curr->val;
                if(even_level){
                    if(value%2!=0 && value>prev){
                        prev=value;
                    }
                    else return false;
                }
                else{
                    if(value%2==0 && value<prev){
                        prev=value;
                    }
                    else return false;
                }

                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
            }
            level++;
        }
        return true;
    }
};
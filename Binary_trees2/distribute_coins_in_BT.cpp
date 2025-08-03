class Solution {
    public:
        int get_steps(TreeNode* &root,int &steps){
            if(!root) return 0;
            int left_required=get_steps(root->left,steps);
            int right_required=get_steps(root->right,steps);
            steps+=abs(left_required) + abs(right_required);
            return (root->val-1)+left_required+right_required;
        }
        int distributeCoins(TreeNode* root) {
            int steps=0;
            get_steps(root,steps);
            return steps;
        }
    };

// a lill description given in copy after greedy portion
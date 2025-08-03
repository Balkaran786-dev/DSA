/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* new_node=new TreeNode(val);
            new_node->left=root;
            return new_node;
        }
        int dep = 1;
        queue<TreeNode*> qu;
        qu.push(root);
        while (dep != depth - 1) {
            int sz = qu.size();
            while (sz--) {
                TreeNode* curr = qu.front();
                qu.pop();

                if (curr->left)
                    qu.push(curr->left);
                if (curr->right)
                    qu.push(curr->right);
            }
            dep++;
        }

        while (!qu.empty()) {
            TreeNode* curr = qu.front();
            qu.pop();
            TreeNode* l = curr->left;
            TreeNode* r = curr->right;
            TreeNode* new_node1 = new TreeNode(val);
            curr->left = new_node1;
            new_node1->left = l;
            TreeNode* new_node2 = new TreeNode(val);
            curr->right = new_node2;
            new_node2->right = r;
        }

        return root;
    }
};
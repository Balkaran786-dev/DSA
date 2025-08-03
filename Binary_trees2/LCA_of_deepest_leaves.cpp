//similar question is Smallest Subtree with all the Deepest Nodes
//done in 2 traversals
class Solution {
public:
    unordered_map<int, int> mp;
    int maxD = 0;
    TreeNode* LCA(TreeNode* root) {
        if (!root || mp[root->val] == maxD)
            return root;

        TreeNode* l = LCA(root->left);
        TreeNode* r = LCA(root->right);

        if (l && r)
            return root;

        else if (l)
            return l;
        else if (r)
            return r;

        return NULL;
    }
    void Find_Depth(TreeNode* root, int d) {
        if (root == NULL)
            return;

        maxD = max(maxD, d);
        mp[root->val] = d;
        Find_Depth(root->left, d + 1);
        Find_Depth(root->right, d + 1);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        Find_Depth(root, 0);
        // o(n)
        return LCA(root);
    }
};
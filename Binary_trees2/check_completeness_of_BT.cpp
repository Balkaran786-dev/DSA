class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr)
            return true;

        queue<TreeNode*> q{{root}};

        while (q.front() != nullptr) {
            TreeNode* node = q.front();
            q.pop();
            q.push(node->left);
            q.push(node->right);
        }

        // Remove any remaining null nodes from the front of the queue
        while (!q.empty() && q.front() == nullptr)
            q.pop();

        // Check if there are any remaining nodes in the queue
        // If so, the tree is not complete, so return false
        // Otherwise, the tree is complete, so return true
        return q.empty();
    }
};
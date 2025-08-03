//there is just a catch of passed by reference in this,
// rather than that, we need to know just the concept of inorder traversal
class Solution {
public:
    int maxi = 0;
    vector<int> ans;
    void fun(TreeNode* root, int &prev, int& cnt) {

        if (!root)
            return;

        fun(root->left, prev, cnt);
        if (prev == root->val)
            cnt++;
        else
            cnt = 1;
        if (cnt == maxi) {
            ans.push_back(root->val);
        } else if (cnt > maxi) {
            ans.clear();
            maxi=max(maxi,cnt);
            ans.push_back(root->val);
        }
        prev=root->val;
        fun(root->right, prev, cnt);
    }
    vector<int> findMode(TreeNode* root) {
        int cnt = 0;
        int prev = INT_MIN;
        fun(root, prev, cnt);
        return ans;
            
    }
};
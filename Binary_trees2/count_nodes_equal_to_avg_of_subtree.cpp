/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> fun(TreeNode* root,int &cnt){
        if(root==NULL) return {0,0};
        
        if(!root->left && !root->right){
            cnt++;
            return {root->val,1};
        }

        pair<int,int> l=fun(root->left,cnt);
        pair<int,int> r=fun(root->right,cnt);
        if(((l.first+r.first+root->val)/(l.second+r.second+1))==root->val) cnt++;
        return {l.first+r.first+root->val,l.second+r.second+1};
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        fun(root,cnt);
        return cnt;
    }
};
/*
Here we have done indexing kind of thing,
i mean for 0-based Indexing,
left child at 2*i+1 and right at 2*i+2 if parent at i,
but if we solely do this,
an edge case is if the tree is skewed and it extends to the worst length 10^5
then index for last ele will be approx equal to 2^(10^5);
so, To avoid this overflow, we can start from 0,
and at every level, which one is having the smallest index(obviusly the first one at that level)
we will subtract that index from all, and then we will calculate index for its childs,

at every level,the width will be the difference between the indices of the first and last node,,,,

*/
class Solution {
    public:
        int widthOfBinaryTree(TreeNode* root) {
            int width=1;
            queue<pair<TreeNode*,long long>> qu;
            qu.push({root,0});
            while(!qu.empty()){
                int last=0;
                int first=0;
                long long mmin=qu.front().second;
                int sz=qu.size();
                for(int i=0;i<sz;i++){
                    long long curr_id=qu.front().second-mmin;
                    TreeNode* curr=qu.front().first;
                    qu.pop();
                    if(i==0) first=curr_id;
                    if(i==sz-1) last=curr_id;
                    if(curr->left) qu.push({curr->left,2*1LL*curr_id+1});
                    if(curr->right) qu.push({curr->right,2*1LL*curr_id+2});
                }
                width=max(width,last-first+1);
            }
            return width;
        }
    };
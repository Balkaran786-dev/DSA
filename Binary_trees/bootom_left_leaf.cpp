class Solution {
public:
    int bottom_left_leaf(TreeNode* root_node){
     vector<int> ans;
     

     queue<TreeNode*> qu;
     qu.push(root_node);
     
     while(!qu.empty()){
        int nodes_at_curr_level=qu.size();
        int a=qu.size();
        while(nodes_at_curr_level){
            TreeNode* curr_node=qu.front();

            if(curr_node->left){
                qu.push(curr_node->left);
            }
            if(curr_node->right){
                qu.push(curr_node->right);
            }
            if(nodes_at_curr_level==a){  //leftmost ele of the level.
                ans.push_back(curr_node->val);
            }
            qu.pop();
            nodes_at_curr_level--;
            
        }
     }
     return ans.back();

    }
    int findBottomLeftValue(TreeNode* root) {
        return bottom_left_leaf(root);
    }
};
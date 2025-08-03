class Solution {
public:
    void levelorder_traversal(TreeNode* root_node,vector<vector<int>> &ans){
     if(root_node==NULL){  
        return;
     }
     stack<int> st;
     vector<int> temp;
     queue<TreeNode*> qu; 
     qu.push(root_node); 
     int mark=0;
     while(!qu.empty()){
        int nodes_at_curr_level=qu.size();
        while(nodes_at_curr_level!=0){
            TreeNode* curr_node=qu.front();
            qu.pop();
            if(mark==1){
               st.push(curr_node->val);
            }
            else{
               temp.push_back(curr_node->val);
            }
            
            if(curr_node->left){
                qu.push(curr_node->left);
            }
            if(curr_node->right){
                qu.push(curr_node->right);
            }
            nodes_at_curr_level--;
        }
        if(mark==1){
            while(!st.empty()){
                temp.push_back(st.top());
                st.pop();
            }
            mark=0;
            ans.push_back(temp);
            temp.clear();
        }
        else{
            ans.push_back(temp);
            temp.clear();
            mark=1;
        }
     }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        levelorder_traversal(root,ans);
        return ans;
    }
};
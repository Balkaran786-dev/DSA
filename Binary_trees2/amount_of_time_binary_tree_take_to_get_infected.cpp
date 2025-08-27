class Solution {
public:
    void fill_map(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp,int start,TreeNode* &startNode){
        if(root==NULL) return;
        if(root->val==start) startNode=root;
        if(root->left){
            mp[root->left]=root;
            fill_map(root->left,mp,start,startNode);
        }
        if(root->right){
            mp[root->right]=root;
           fill_map(root->right,mp,start,startNode);
        }
        return;
    }
    
    int amountOfTime(TreeNode* root, int start) {
       if(root->left==NULL && root->right==NULL) return 0;
        unordered_map<TreeNode*,TreeNode*> mp;
        mp[root]=NULL;
        TreeNode* startNode=NULL;
        fill_map(root,mp,start,startNode);
        unordered_set<int> st;  //to make sure the already infected node is not processed again
        queue<TreeNode*> qu;
        int time=0;
        qu.push(startNode);
         
        while(!qu.empty()){
            bool infect_flag=false;
            int nodes_same_dist=qu.size();
            while(nodes_same_dist--){
                TreeNode* node=qu.front();
                qu.pop();
                st.insert(node->val);
                TreeNode* parent=mp[node];
                if(parent && !st.count(parent->val)){
                    infect_flag=true;
                   qu.push(parent);
                }
                if(node->left && !st.count(node->left->val)){
                    qu.push(node->left);
                    infect_flag=true;
                }
                if(node->right && !st.count(node->right->val)){
                    qu.push(node->right);
                    infect_flag=true;
                }
            }
            if(infect_flag){
                time++;
            }
        }

        return time;
    }
};
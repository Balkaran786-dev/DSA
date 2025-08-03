class Solution {
public:
    int minSwaps(vector<int>& arr) {   
        vector<pair<int,int>> vec;
        for(int i=0;i<arr.size();i++){
            vec.push_back(make_pair(arr[i],i));
        }
        sort(vec.begin(),vec.end());
        int total_swaps=0;
        for(int i=0;i<vec.size();i++){
            int val=vec[i].first;
            int idx=vec[i].second;
            if(idx!=i){
                total_swaps++;
                swap(vec[i],vec[idx]);
                i--;
            }
        }
        return total_swaps;
    }
    int minimumOperations(TreeNode* root) {
        
        //we will be combining level order + quick sort
        if(!root->left && !root->right) return 0;
        queue<TreeNode*> qu;
        qu.push(root);
        int swaps=0;
        vector<int> temp;
        while(!qu.empty()){
             int nodes_at_same_level=qu.size();
             while(nodes_at_same_level--){
                TreeNode* node=qu.front();
                qu.pop();
                temp.push_back(node->val);
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
             }
             swaps+=minSwaps(temp);
             temp.clear(); 
        }
        return swaps;
    }
};
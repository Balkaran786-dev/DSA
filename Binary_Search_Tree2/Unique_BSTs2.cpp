class Solution {
public:
    vector<TreeNode*> generateTrees_helper(int start,int end){
        vector<TreeNode*> treelist;
        if(start>end){
            treelist.push_back(NULL);
            return treelist;
        }

        for(int i=start;i<=end;i++){  //making all nodes from start to end as root node one by one
             vector<TreeNode*> leftSubtrees=generateTrees_helper(start,i-1);
             vector<TreeNode*> rightSubtrees=generateTrees_helper(i+1,end);
             
             TreeNode* root=new TreeNode(start);
             for(TreeNode* leftsubtree: leftSubtrees){
                for(TreeNode* rightsubtree: rightSubtrees){
                    root->left=leftsubtree;
                    root->right=rightsubtree;
                    
                }
             }
        }
    }
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees_helper(1,n);
    }
};

//by using dp also to make solution more optimised..
class Solution {
public:
    vector<vector<vector<TreeNode*>>> dp;
    vector<TreeNode*> generateTrees_helper(int start,int end){
        vector<TreeNode*> treelist;
        if(start>end){
            treelist.push_back(NULL);
            return treelist;
        }
        if(!dp[start][end].empty()){
            return dp[start][end];
        }
        for(int i=start;i<=end;i++){  //making all nodes from start to end as root node one by one
             vector<TreeNode*> leftSubtrees=generateTrees_helper(start,i-1);
             vector<TreeNode*> rightSubtrees=generateTrees_helper(i+1,end);
             
             for(TreeNode* leftsubtree: leftSubtrees){
                for(TreeNode* rightsubtree: rightSubtrees){
                    TreeNode* root=new TreeNode(i);
                    root->left=leftsubtree;
                    root->right=rightsubtree;
                    treelist.push_back(root);
                }
             }
        }

        dp[start][end]=treelist;
        return treelist;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> p;
        dp.resize(n+1);
        for(int i=0;i<n+1;i++){
            dp[i].resize(n+1,p);
        }
        return generateTrees_helper(1,n);
    }
};
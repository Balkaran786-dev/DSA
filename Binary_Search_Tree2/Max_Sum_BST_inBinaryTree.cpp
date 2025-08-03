class NodeInfo{
public:
    int minval;
    int maxval;
    int maxCurrentSum;
    NodeInfo(int minval,int maxval,int maxCurrentSum){
        this->minval=minval;
        this->maxval=maxval;
        this->maxCurrentSum=maxCurrentSum;
    }
};
class Solution {
public:
    int ans=0;
    NodeInfo maxSumBSTHelper(TreeNode* root){
        if(!root) return NodeInfo(INT_MAX,INT_MIN,0);  //anonymous object
        NodeInfo leftSubtree=maxSumBSTHelper(root->left);
        NodeInfo rightSubtree=maxSumBSTHelper(root->right);
        if(root->val>leftSubtree.maxval && root->val<rightSubtree.minval){
            //root forms a BST
            ans=max(ans,root->val+leftSubtree.maxCurrentSum+rightSubtree.maxCurrentSum);
            return NodeInfo(min(leftSubtree.minval,root->val),max(root->val,rightSubtree.maxval),root->val+leftSubtree.maxCurrentSum+rightSubtree.maxCurrentSum);
        }
        //root does not form BST
        return NodeInfo(INT_MIN,INT_MAX,max(leftSubtree.maxCurrentSum,rightSubtree.maxCurrentSum));
    }
    int maxSumBST(TreeNode* root) {
        maxSumBSTHelper(root);
        return ans;
    }
};
class Solution {
public:
    bool find_if_balanced(TreeNode* &root,int &nodes){
        if(!root){
            nodes=0;
            return true;
        }
        else if(!root->left && !root->right){
             nodes=1;
             return true;
        }
        
        bool b1=find_if_balanced(root->left,nodes);
        if(!b1) return false;
        int leftNodes=nodes;
        bool b2=find_if_balanced(root->right,nodes);
        if(!b2) return false;
        int rightNodes=nodes;
        if(abs(leftNodes-rightNodes)<2){
            nodes=1+max(leftNodes,rightNodes);
            return true;
        }
        return false;
    }
    bool isBalanced(TreeNode* root) {
        int nodes=0;
        return find_if_balanced(root,nodes);
    }
};

//at every node,you need to check for its balance factor and also store how
//the max depth of that node. that we will use for the nodes upper to it...




class Solution {
public:
    
    int get_depth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        else if(root->left==NULL && root->right==NULL){
            return 1;
        }
        else if(root->left==NULL){  //it is important to mention these cases otherwise if you do it just like max depth and just change 
        //max with min,you will get a lot of testcases wrong..
        //just consider a skewed tree,you will just be getting 1 as its ans,
        //but its min depth is actually n.,similar to this,assume a zig zag tree.
        //you will gwt to know,that algo won't be giving right ans,so 
        //if your root node is having no child node return 1,if it having only one child just add curr
        // node to it and move to its dubtree,but if you have both the child nodes,add 
        //1 to min_depth  from both the subtrees. 
            return 1+get_depth(root->right);
        }
        else if(root->right==NULL){
             return 1+get_depth(root->left);
        }
        
        return 1+min(get_depth(root->left),get_depth(root->right));
    }
    
    int minDepth(TreeNode* root) {
        return get_depth(root);
    }
};



//OR

class Solution {
public:
   
   int get_depth(TreeNode* root){
       if(root==NULL){
           return INT_MAX;
       }
       else if(root->left==NULL && root->right==NULL){
           return 1;
       }
       return 1+min(get_depth(root->left),get_depth(root->right));
   }
   
   int minDepth(TreeNode* root) {
       if(root==NULL) return 0;
       return get_depth(root);
   }
};
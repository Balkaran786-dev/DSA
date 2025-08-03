
class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int helper(Node* &root){
        
        if(!root) return 1;
        
        int left_part=helper(root->left);
        if(left_part==0) return 0;
        int right_part=helper(root->right);
        if(right_part==0) return 0;
        
    
        if(!root->left && !root->right) return 1;
        if(!root->left) return (root->data==root->right->data?1:0);
        else if(!root->right) return (root->data==root->left->data?1:0);
        
        return (root->data==(root->right->data+root->left->data)?1:0);
        
    }
    int isSumProperty(Node *root)
    {
     // Add your code here
     return helper(root);
    }
};


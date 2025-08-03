
int max_size=0;
class NodeInfo{
    public:
    int max_val;
    int min_val;
    int nodes;

    NodeInfo(int val1,int val2,int n){
        max_val=val1;
        min_val=val2;
        nodes=n;
    }
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    NodeInfo get_larg_BST(Node* &root){
    if(!root) return NodeInfo(INT_MIN,INT_MAX,0);

    NodeInfo left_part=get_larg_BST(root->left);
    NodeInfo right_part=get_larg_BST(root->right);

    if(root->data>left_part.max_val && root->data<right_part.min_val){  //form BST
        max_size=max(max_size,1+left_part.nodes+right_part.nodes);
        return NodeInfo(max(root->data,right_part.max_val),min(root->data,left_part.min_val),1+left_part.nodes+right_part.nodes);
    }

    return NodeInfo(INT_MAX,INT_MIN,max(left_part.nodes,right_part.nodes));
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	NodeInfo N=get_larg_BST(root);
        return N.nodes;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

  


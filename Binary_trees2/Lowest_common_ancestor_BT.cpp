//Intuition:
/*
hum postorder way mein bottom up approach lgakar,yeh find krna chahte hain ki
current node ke left sub ya right right sub ya dono mein koip ya q hai present,
uske hissab se,we can decide the LCA.

if hum iss way mein,ek jagah jaakr left mein p and right mein q mil gya,toh voh 
node hi LCA hoga...*/
class Solution {
    
public:
    TreeNode* get_LCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL || root->val==p->val || root->val==q->val) return root;  //may be that root is one of our given node or root is NULL

        TreeNode* left_sub=get_LCA(root->left,p,q);  //post order
        TreeNode* right_sub=get_LCA(root->right,p,q);

        if(!left_sub && !right_sub) return NULL;  //if both NULL
        if(left_sub && right_sub ) return root;  //if left subtree mein p or q  present hai and right subtree 
        //mein q or p presnt hai, means yeah root node hi uski LCA hai
        if(!left_sub && right_sub) return right_sub; //if sirf right subtree mein mila
        return left_sub;  //if sirf left subtree mein mila
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return get_LCA(root,p,q);
    }
};




// OR

//mine solution..  4 cases possible honge, ihave written along code
class Solution {
    public:
        bool get_LCA(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &LCA){
            if(root==NULL) return false;
            if(!root->left && !root->right){
                return (root->val==p->val || root->val==q->val);
            }  
    
            bool left_sub=get_LCA(root->left,p,q,LCA);  //post order
            bool right_sub=get_LCA(root->right,p,q,LCA);
    
            if(left_sub && right_sub){  // this is the LCA,
                LCA=root;
                return false;  // so that upper vale kabhi LCA na bna abb
            }
            else if(left_sub || right_sub){      // matlab ek toh mil gya
                if(root->val==p->val || root->val==q->val){  //checking dusre vala yehi node ho, then this is the LCA
                    LCA=root;
                    return false;
                }
                return true;  //  otherwise, return true,
            }
            if(root->val==p->val || root->val==q->val){  // agr yeh node us ek brabr hai, then also return true.
                    return true;
            }
            return false;
        }
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            TreeNode* LCA=NULL;
            get_LCA(root,p,q,LCA);
            return LCA;
        }
    };
class Solution {
    public:
        int get_diameter(TreeNode* &root,int &maxi){
            if(root==NULL) return -1;
    
            int left_max=get_diameter(root->left,maxi);
            int right_max=get_diameter(root->right,maxi);
    
            if(left_max==-1 && right_max==-1){
                maxi=max(maxi,0);
                return 0;
            }
            else if(left_max==-1){
                maxi=max(maxi,1+right_max);
                return 1+right_max;
            }
            else if(right_max==-1){
                maxi=max(maxi,1+left_max);
                return 1+left_max;
            }
            
            maxi=max(maxi,2+left_max+right_max);
            return 1+max(right_max,left_max);
            
        }
        int diameterOfBinaryTree(TreeNode* root) {
            int maxi=INT_MIN;
            get_diameter(root,maxi);
            return maxi;
        }
    };
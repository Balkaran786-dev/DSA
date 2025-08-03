
class Solution {
public:
    int get_value(string &str,int &idx){
        int start=idx;
        while(idx<str.size() && str[idx]!='-'){
            idx++;
        }
        return stoi(str.substr(start,idx-start));
    }
    void recover(string &str,TreeNode* &root,int &idx,int count,int n){
        if(idx>=n) return;

        if(str.substr(idx,count)==string(count,'-')){
            idx+=count;
            TreeNode* left_child=new TreeNode(get_value(str,idx));
            root->left=left_child;
            recover(str,root->left,idx,count+1,n);
            if(str.substr(idx,count)==string(count,'-')){
                idx+=count;
                TreeNode* right_child=new TreeNode(get_value(str,idx));
                root->right=right_child;
                recover(str,root->right,idx,count+1,n);
            }
            else{
                root->right=NULL;
            }
        }
        else{
            root->left=NULL;
            root->right=NULL;
        }
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int n=traversal.size();
        int idx=0;
        int root_value=get_value(traversal,idx);
        TreeNode* root=new TreeNode(root_value);
        recover(traversal,root,idx,1,n);
        return root;
    }
};
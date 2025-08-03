//here we need to print all the paths starting from root node to a leaf node
//whose sum gets equal to the targetSum...


class Solution {
public:
    void get_paths(TreeNode* root,vector<vector<int>> &all_paths,vector<int> &temp,int sum,int targetSum){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
           if(sum+root->val==targetSum){
               temp.push_back(root->val);
               all_paths.push_back(temp);
               temp.pop_back();
                return;
           }
           else{
               return;
           }  
        }
        
        temp.push_back(root->val);
        get_paths(root->left,all_paths,temp,sum+root->val,targetSum);
        get_paths(root->right,all_paths,temp,sum+root->val,targetSum);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> all_paths;
        vector<int> temp;
        get_paths(root,all_paths,temp,0,targetSum);
        return all_paths;
    }
};
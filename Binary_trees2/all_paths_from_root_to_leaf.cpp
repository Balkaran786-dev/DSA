
class Solution {
  public:
    void get_paths(Node* &root,vector<int> &temp,vector<vector<int>> &all_paths){
        if(root==NULL) return;
        
        if(!root->left && !root->right){
            temp.push_back(root->data);
            all_paths.push_back(temp);
            temp.pop_back();
            return;
        }
        
        temp.push_back(root->data);
        get_paths(root->left,temp,all_paths);
        get_paths(root->right,temp,all_paths);
        temp.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> all_paths;
        vector<int> temp;
        get_paths(root,temp,all_paths);
        return all_paths;
    }
};



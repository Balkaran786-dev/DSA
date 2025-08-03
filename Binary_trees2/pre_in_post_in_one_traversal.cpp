vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>> vec(3,vector<int> ());
    if(!root) return vec;
    stack<pair<TreeNode*,int>> st;
    st.push({root,1});
    while(!st.empty()){
        pair<TreeNode*,int> pp=st.top();
        st.pop();
        if(pp.second==1){            // when get num=1, put it in preorder, increment it to 2, and push back the same node in stack, also put the left node with num=1, in stack if present.
            vec[1].push_back(pp.first->data);
            st.push({pp.first,2});
            if(pp.first->left){
               st.push({pp.first->left,1});
            }
        }
        else if(pp.second==2){    // when get num=2, put it in inorder, increment it to 3, and push back the same node in stack, also put the right node with num=1, in stack if present.
            vec[0].push_back(pp.first->data);
            st.push({pp.first,3});
            if(pp.first->right){
               st.push({pp.first->right,1});
            }
        }
        else{                    // when get num=3, put it in postorder...
            vec[2].push_back(pp.first->data);
        }
    }
    return vec;
}


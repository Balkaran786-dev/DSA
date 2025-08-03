/* preorder=[3,9,20,15,7]  inorder=[9,3,15,20,7]
we are given preorder and inorder traversal;
preorder ka first ele is always going to the root_node.
so,3 is our root node.
but we don't know,how many ele are in left and right subtree.
for that,we take help of inorder traversal.

In inorder,root will come in between the inorder traversal,and it basically 
divides the set into two sets,the left side elements are present in left subtree and so with right side elemenst. 
so,we get to know that 9 will be in left and 15,20,7 will be in right subtree.

again recursively we see, in right subtree:15,20,7-inorder  20,15,7:preorder
20 will be the root node,
20 divides the 15,20,7 into two sets,the left side elements are present in left subtree and so with right side elemenst. 

in this way,we can find the whole BT recursively.
*/

#include<iostream>    //o(n)-time and space complexity.
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
class Node{
public:
     int value;
     Node* left;
     Node* right;

     Node(int val){
       value=val;
       left=right=NULL;
     }

};
void levelorder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> qu;
    qu.push(root);
    while(!qu.empty()){
        int nodes_at_level=qu.size();
        while(nodes_at_level!=0){
            Node* curr_node=qu.front();
            qu.pop();
            cout<<curr_node->value<<" ";   //printing the curr_node
            if(curr_node->left){            //inserting the left child if present
                qu.push(curr_node->left);
            }
            if(curr_node->right){           //inserting the right child if present
                qu.push(curr_node->right);
            }
            nodes_at_level--;
        }
        cout<<"\n";
    }
}
Node* maketreehelper(vector<int> &preorder,int prestart,int pre_end,vector<int> &inorder,int instart,int inend,unordered_map<int,int> &inmap){
    if(prestart>pre_end || instart>inend){
        return NULL;  
    }
    
    Node* root_node=new Node(preorder[prestart]);
    if(pre_end==prestart){  //handling the leaf nodes  if prestart == preend then obviously instrat will be equal to inend.
        return root_node;
    }

    int rootinorder_index=inmap[root_node->value];
    int left_subtree_ele=rootinorder_index-instart;
    root_node->left=maketreehelper(preorder,prestart+1,prestart+left_subtree_ele,inorder,instart,rootinorder_index-1,inmap);
    root_node->right=maketreehelper(preorder,prestart+left_subtree_ele+1,pre_end,inorder,rootinorder_index+1,inend,inmap);

    return root_node;

}
Node* maketree(vector<int> &preorder,vector<int> &inorder){
    unordered_map<int,int> inmap;
    for(int i=0;i<inorder.size();i++){
        inmap[inorder[i]]=i;    //storing index of all the inorder elements in inmap as value corresponding to their node values as key.
    }
    return maketreehelper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);
}
int main(){
    vector<int> preorder={3,9,10,11,20,15,7};
    vector<int> inorder={10,9,11,3,15,20,7};
    Node* root_node=maketree(preorder,inorder);
    levelorder(root_node);
    return 0;
}


// class Solution {
// public:
//     unordered_map<int,int> mp;
//     TreeNode* get_tree(vector<int> &preorder,vector<int> &inorder,int prestart,int pre_end,int instart,int inend){
//            if(prestart>pre_end || instart>inend){
//              return NULL;
//            }
//            int root_value=preorder[prestart];
//            TreeNode* root=new TreeNode(root_value);
//            int root_idx=mp[root_value];
//            int left_subtree_ele=root_idx-instart;
//            root->left=get_tree(preorder,inorder,prestart+1,prestart+left_subtree_ele,instart,root_idx-1);
//            root->right=get_tree(preorder,inorder,prestart+left_subtree_ele+1,pre_end,root_idx+1,inend);
//            return root;
//     }
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         for(int i=0;i<inorder.size();i++){
//             mp[inorder[i]]=i;
//         }
//         TreeNode* root_node=get_tree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
//         return root_node;
//     }
// };
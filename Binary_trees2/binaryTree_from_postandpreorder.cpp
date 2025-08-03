/* preorder-[1,2,4,5,3,6,7] postorder-[4,5,2,6,7,3,1]
preorder mein 1st ele is root node,and uske just next vala 
ele for sure will be in the left subtree and its first left child.
hence 2 is for sure in left subtree,so in postorder{left,right,root}
2 and 2 se pehle ke saare ele are going to be in left subtree.
and 2 se baad ke saare ele except last ele are going to be in right subtree.
*/

//there can be multiple answers.
// //so to find any one of it, we are assuming that after root_node,there is a left child.
// #include<iostream>    //o(n)-time and space complexity.
// #include<unordered_map>
// #include<vector>
// #include<queue>
// using namespace std;
// class Node{
// public:
//      int value;
//      Node* left;
//      Node* right;

//      Node(int val){
//        value=val;
//        left=right=NULL;
//      }

// };
// void levelorder(Node* root){
//     if(root==NULL){
//         return;
//     }
//     queue<Node*> qu;
//     qu.push(root);
//     while(!qu.empty()){
//         int nodes_at_level=qu.size();
//         while(nodes_at_level!=0){
//             Node* curr_node=qu.front();
//             qu.pop();
//             cout<<curr_node->value<<" ";   //printing the curr_node
//             if(curr_node->left){            //inserting the left child if present
//                 qu.push(curr_node->left);
//             }
//             if(curr_node->right){           //inserting the right child if present
//                 qu.push(curr_node->right);
//             }
//             nodes_at_level--;
//         }
//         cout<<"\n";
//     }
// }
// Node* maketreehelper(vector<int> &preorder,int prestart,int pre_end,vector<int> &postorder,int poststart,int postend,unordered_map<int,int> &postmap){
//     if(prestart>pre_end || poststart>postend){
//         return NULL;  
//     }
    
//     Node* root_node=new Node(preorder[prestart]);
//     if(pre_end==prestart){  //handling the leaf nodes  if prestart == preend then obviously instart will be equal to inend.
//         return root_node;
//     }
//     int first_left_child=preorder[prestart+1];
//     int first_left_post_idx=postmap[first_left_child];
//     int left_subtree_ele=(first_left_post_idx-poststart)+1;
//     root_node->left=maketreehelper(preorder,prestart+1,prestart+left_subtree_ele,postorder,poststart,first_left_post_idx,postmap);
//     root_node->right=maketreehelper(preorder,prestart+left_subtree_ele+1,pre_end,postorder,first_left_post_idx+1,postend-1,postmap);
    
//     return root_node;

// }
// Node* maketree(vector<int> &preorder,vector<int> &postorder){
//     unordered_map<int,int> postmap;
//     for(int i=0;i<postorder.size();i++){
//         postmap[postorder[i]]=i;    //storing index of all the postorder elements in postmap as value corresponding to their node values as key.
//     }
//     return maketreehelper(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1,postmap);
// }
// int main(){
//     vector<int> preorder={1,2,3,4,5,6,7};
//     vector<int> postorder={7,6,5,4,3,2,1};
//     Node* root_node=maketree(preorder,postorder);
//     levelorder(root_node);
//     return 0;
// }

//isme mene esa socha:
/*
first ele of preorder -> root node
lastele of postorder -> root node
the ele just before that last ele in postorder will surely be in right subtree.
so,we find its idx in preoder using map,
now,from prestart to idx-1 will be in left subtree and idx to pre_end in right_subtree
int left_subtree_ele=idx-prestart-1;
in postorder,poststart to poststart+left_subtree_ele-1 in leftsubtree and from poststart+left_subtree_ele to postend-1 in right

one more base case,when we reach on leaf node i.e prestart==pre_end,
we need to return it there only.. otherwise it gives error because ahead,we calculate idx for
pre_end-1 which can go out of scope sometimes.*/


class Solution {
public:
    unordered_map<int,int> mp;
    TreeNode* get_tree(vector<int>& preorder, vector<int>& postorder,int prestart,int pre_end,int poststart,int postend){
        if(prestart>pre_end || poststart>postend){
            return NULL;
        }
        
        int curr_node_val=preorder[prestart];
        TreeNode* curr=new TreeNode(curr_node_val);
        if(prestart==pre_end){   //if this won't be handled,so this creates an error kyunki postend-1 mein it can go out of scope in some cases,so its better to handle it here...
            return curr;
        }
        int idx=mp[postorder[postend-1]];
        int left_subtree_ele=idx-prestart-1;
        curr->left=get_tree(preorder,postorder,prestart+1,idx-1,poststart,poststart+left_subtree_ele-1);
        curr->right=get_tree(preorder,postorder,idx,pre_end,poststart+left_subtree_ele,postend-1);
        return curr;

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
       
        for(int i=0;i<preorder.size();i++){
            mp[preorder[i]]=i;
        }
        TreeNode* root=get_tree(preorder,postorder,0,preorder.size()-1,0,postorder.size()-1);
        return root;
    }
    
};
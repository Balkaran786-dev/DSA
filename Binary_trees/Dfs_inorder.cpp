#include<bits/stdc++.h>
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

void inorder_traversal(Node* root_node){
  if(root_node==NULL) return;
   stack<Node*> st;
   Node* curr=root_node;

   while(curr!=NULL || !st.empty()){
         while(curr!=NULL){
          st.push(curr);
          curr=curr->left;
         }
         
         if(!st.empty()){
          curr=st.top();
          st.pop();
          cout<<curr->value<<" ";
          curr=curr->right;
         }
   }

}
// void inorder_traversal(Node* root_node){
//     //Base case. when we try to go ahead of leaf node
//     if(root_node==NULL){
//         return;
//     }
    
//     //calling for left subtree or left child
//     inorder_traversal(root_node->left);
//     //printing the value of curr_node whose left subtree pe hum abhi gaye thee
//     cout<<root_node->value<<" ";
//     //calling for right subtree or right child
//     inorder_traversal(root_node->right);
// }
int main(){
    Node* root=new Node(2);
    root->left=new Node(4);
    root->right=new Node(10);
    root->left->left=new Node(6);
    root->left->right=new Node(5);
    root->right->right=new Node(11);
    inorder_traversal(root);
    return 0;
}

/*
     2
   4   10
  6 5    11

*/
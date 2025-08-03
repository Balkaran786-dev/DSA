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

//iterative approach
void preorder_traversal(Node* root_node){
  if(root_node==NULL) return;
   stack<Node*> st;
   Node* curr=root_node;
   
   while(curr!=NULL || !st.empty()){
    
     while(curr!=NULL){
        cout<<curr->value<<" ";
        if(curr->right) st.push(curr->right);
        curr=curr->left;
     }

     if(!st.empty()){
          curr=st.top();
          st.pop();
     }
     
   }
}
// void preorder_traversal(Node* root_node){
//     //Base case. when we try to go ahead of leaf node
//     if(root_node==NULL){
//         return;
//     }
    
//     //pehle curr_node ki val print ki
//     cout<<root_node->value<<" ";
//     //calling for left subtree or left child
//     preorder_traversal(root_node->left);
//     //calling for right subtree or right child
//     preorder_traversal(root_node->right);
// }
int main(){
    Node* root=new Node(2);
    root->left=new Node(4);
    root->right=new Node(10);
    root->left->left=new Node(6);
    root->left->right=new Node(5);
    root->right->right=new Node(11);
    preorder_traversal(root);
    return 0;
}

/*
     2
   4   10
  6 5    11

*/
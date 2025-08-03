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



void postorder_traversal(Node* root){

  if(root==NULL) return;
   stack<Node*> st1,st2;
   Node* curr=root;
   
   st1.push(curr);
   while(!st1.empty()){
    Node* node=st1.top();
    st1.pop();
    st2.push(node);

    if(node->left) st1.push(node->left);
    if(node->right) st1.push(node->right);
   }

   while(!st2.empty()){
    cout<<st2.top()->value<<" ";
    st2.pop();
   }

}
// void postorder_traversal(Node* root_node){
//     //Base case. when we try to go ahead of leaf node
//     if(root_node==NULL){
//         return;
//     }
    
//     //calling for left subtree or left child
//     postorder_traversal(root_node->left);
//     //calling for right subtree or right child
//     postorder_traversal(root_node->right);
//     //printing the value of curr_node whose left subtree and right subtree pe hum abhi gaye thee
//     cout<<root_node->value<<" ";
//}
int main(){
    Node* root=new Node(2);
    root->left=new Node(4);
    root->right=new Node(10);
    root->left->left=new Node(6);
    root->left->right=new Node(5);
    root->right->right=new Node(11);
    postorder_traversal(root);
    return 0;
}

/*
     2
   4   10
  6 5    11

*/
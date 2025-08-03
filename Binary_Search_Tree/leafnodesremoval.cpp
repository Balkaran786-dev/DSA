#include<iostream>
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
class Bst{
public:
     Node* root;

     Bst(){
        root=NULL;
     }
};
Node* insert(Node* root_node,int data){  //we can pass root by refernce becuse last call tak aate aate vo NULL ko point kardega.isliye humne usse return hi karvaddeya.
     //base case
     if(root_node==NULL){  //handle the empty tree and the empty spot for inserting the new node
        Node* new_node=new Node(data);
        return new_node;
     }
      
     //recursive case
     if(root_node->value>data){
        root_node->left=insert(root_node->left,data);
     }
     else{
        root_node->right=insert(root_node->right,data);
     }
     return root_node;

}
void preorder_traversal(Node* root_node){
    if(root_node==NULL){
        return;
    }

    cout<<root_node->value<<" ";
    preorder_traversal(root_node->left);
    preorder_traversal(root_node->right);
}
Node* remove_leaf_nodes(Node* root){
    if(root==NULL){
        return NULL;
    }

    if(root->left==NULL && root->right==NULL){ //leaf node
       return NULL;
    }
    root->left=remove_leaf_nodes(root->left);
    root->right=remove_leaf_nodes(root->right);
    return root;
}
int main(){
    Bst b1;
    b1.root=insert(b1.root,5);
    insert(b1.root,9);
    insert(b1.root,3);
    insert(b1.root,4);
    insert(b1.root,2);
    insert(b1.root,11);
    insert(b1.root,8);
    preorder_traversal(b1.root);
    cout<<"\n";
    b1.root=remove_leaf_nodes(b1.root);
    preorder_traversal(b1.root);
    return 0;
}

/*
       5
     3   9
   2  4  8  11
      
*/
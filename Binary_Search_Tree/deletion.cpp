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
Node* justsmallernode(Node* current_node){
       Node* root_node=current_node->left;  //firstly,left subtree mein jayenge and uske sabse rightmost node ko find krenge
       while(root_node->right!=NULL){
           root_node=root_node->right;
       }
       return root_node;
}
Node* deleteBST(Node* root_node,int key){
    if(root_node==NULL){ //may be the tree is empty or the key is not present.
        return NULL;
    }
    
    if(root_node->value>key){
        root_node->left=deleteBST(root_node->left,key);
    }
    else if(root_node->value<key){
        root_node->right=deleteBST(root_node->right,key);
    }
    else{ //the root is the node to be deleted
        if(root_node->left==NULL && root_node->right==NULL){   //it has no child nodes
        free(root_node);
        return NULL;
        }
        else if(root_node->left==NULL){ //only 1 child is present i.e right child
             Node* right_child=root_node->right;
             free(root_node);
             return right_child;
        }
        else if(root_node->right==NULL){ //only 1 child is present i.e left child
             Node* left_child=root_node->left;
             free(root_node);
             return left_child;
        }
        else{   //it has two childs.
           Node* just_smaller=justsmallernode(root_node);
           root_node->value=just_smaller->value;
           root_node->left=deleteBST(root_node->left,just_smaller->value);
        }
    }
    return root_node;
}
void inorder_traversal(Node* root){
    if(root==NULL){
        return;
    }

    inorder_traversal(root->left);
    cout<<root->value<<" ";
    inorder_traversal(root->right);
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
    deleteBST(b1.root,5);

    inorder_traversal(b1.root);

    return 0;
}

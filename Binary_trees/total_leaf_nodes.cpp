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
int total_leafnodes(Node* root_node){
     if(root_node==NULL){
       return 0;  //may be bt is already empty
     }
     else if(root_node->left==NULL && root_node->right==NULL){
        return 1;
     }
     else{
        return total_leafnodes(root_node->left)+total_leafnodes(root_node->right);
     }
}
int main(){
    Node* root=new Node(2);
    root->left=new Node(4);
    root->right=new Node(10);
    root->left->left=new Node(6);
    root->left->right=new Node(5);
    root->left->right->right=new Node(12);
    root->right->right=new Node(11);
    root->right->right->left=new Node(13);
    root->right->right->right=new Node(14);
    cout<<total_leafnodes(root);
    return 0;
}

/*
     2
   4   10
 6   5    11
       12
*/
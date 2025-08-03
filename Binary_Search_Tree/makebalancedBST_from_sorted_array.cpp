#include<iostream>
#include<vector>
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
Node* make_BalancedBST(vector<int> &v,int first,int last){
    if(first>last){
        return NULL;
    }
    if(first==last){   //inserting the leaf nodes
        Node* curr_node=new Node(v[first]);
        return curr_node;
    }

    int mid=(first+last)/2;
    Node* curr_node=new Node(v[mid]);
    curr_node->left=make_BalancedBST(v,first,mid-1);
    curr_node->right=make_BalancedBST(v,mid+1,last);
    return curr_node;
}
void preorder_traversal(Node* root_node){
    if(root_node==NULL){
        return;
    }

    cout<<root_node->value<<" ";
    preorder_traversal(root_node->left);
    preorder_traversal(root_node->right);
}
int main(){
    vector<int> v={1,2,3,4,5,6,7,8};
    Bst b1;
    b1.root=make_BalancedBST(v,0,v.size()-1);
    preorder_traversal(b1.root);
}
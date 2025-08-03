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
Node* LCA(Node* root,int n1,int n2){
     if(root==NULL){  //
        return NULL;
     }
     int curr=root->value;
     if(curr>=n1 && curr<n2){ // root node lies either between n1 and n2 or it is equal to n1 
        return root;
     }
     else if(curr>n1 && curr>n2){ 
        return LCA(root->left,n1,n2);  //LCA lies in left subtree
     }
     else if(curr<n1 && curr<n2){
        return LCA(root->right,n1,n2);  //LCA lies in right subtree
     }
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
    insert(b1.root,1);
    Node* lowest_common_ancestor=LCA(b1.root,8,11);
    cout<<lowest_common_ancestor->value;
    return 0;
}

/*
       5
     3   9
   2  4  8  11
  1    
*/

//leetcode solution done by me
class Solution {
public:
    TreeNode* get_LCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if((root->val>p->val && root->val<q->val) || (root->val<p->val && root->val>q->val) || root->val==p->val || root->val==q->val){
            return root;
        }  // if p is less than and q is greater than curr or vice versa,means here this is the first point where p and q gets in different subtrees,so it will be returned,
    //also if p==curr->val or q==curr->val,that means curr will the LCA
 
        if(root->val>p->val && root->val>q->val){
            return get_LCA(root->left,p,q); //if both are lesser than root,that means both lies in left subtree
        }
        else if(root->val<p->val && root->val<q->val){ //if both are greater than root,that means both lies in right subtree
            return get_LCA(root->right,p,q);
        }
        return NULL; //yeh toh baas vaise hi
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
        return get_LCA(root,p,q);
    }
};
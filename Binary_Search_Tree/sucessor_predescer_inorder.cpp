//predecsor: greatest value smaller than the key.
//successor: smallest value greater than the key.

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
// void inorderBst_pre_succ(Node* root,Node* &pre,Node* &succ,int key){
//       if(root==NULL){  //if tree is empty or we reach the empty spot after a leaf node.
//         return;
//       }

//       if(root->value==key){
//         //for predecessor,we move to left subtree if not NULLand find the rightmost node
//         if(root->left!=NULL){
//             Node* curr=root->left;
//             while(curr->right!=NULL){
//                 curr=curr->right;
//             }
//             pre=curr;
//         }
//         //for successor,we move to right subtree if not NULLand find the leftmost node
//         if(root->right!=NULL){
//             Node* curr=root->right;
//             while(curr->left!=NULL){
//                 curr=curr->left;
//             }
//             succ=curr;
//         }
//         return;
//       }
//       else if(root->value>key){
//         succ=root;  //may be it can be a succ,if not aage jake change ho jayega.
//         inorderBst_pre_succ(root->left,pre,succ,key);
//       }
//       else{
//         pre=root;   //may be it can be a pred,if not aage jake change ho jayega.
//         inorderBst_pre_succ(root->right,pre,succ,key);
//       }
// }


Node* just_smaller_node(Node* root){
  if(root==NULL) return root;
  while(root->right!=NULL){
    root=root->right;
  }
  return root;
}
Node* just_bigger_node(Node* root){
  if(root==NULL) return root;
  while(root->left!=NULL){
    root=root->left;
  }
  return root;
}

void inorderBst_pre_succ(Node* root,Node* &pre,Node* &succ,int key){
     if(root==NULL) return;
     if(root->value==key){
      if(root->left==NULL && root->right==NULL){
        return;
      }
      else if(root->left==NULL){
          succ=just_bigger_node(root->right);
          return;
      }
      else if(root->right==NULL){
        pre=just_smaller_node(root->left);
        return;
      }
      else{
        pre=just_smaller_node(root->left);
        succ=just_bigger_node(root->right);
        return;
      }
     }
     else if(root->value>key){
      succ=root;
      inorderBst_pre_succ(root->left,pre,succ,key);
     }
     else{
      pre=root;
      inorderBst_pre_succ(root->right,pre,succ,key);
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
    Node* pre=NULL;
    Node* succ=NULL;
    inorderBst_pre_succ(b1.root,pre,succ,11);
    if(pre==NULL){
        cout<<"pre - NULL"<<endl;
    }
    else{
        cout<<"pre -"<<pre->value<<endl;
    }
   
    if(succ==NULL){
        cout<<"succ - NULL"<<endl;
    }
    else{
        cout<<"succ -"<<succ->value<<endl;
    }

    return 0;
}
/*
       5
     3   9
   2  4  8  11
     
*/



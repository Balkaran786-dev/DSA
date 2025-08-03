// iterative approach
// #include<iostream>
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
// class Bst{
// public:
//      Node* root;

//      Bst(){
//         root=NULL;
//      }
// };
// void insert(Node* &root_node,int data){
//     Node* new_node=new Node(data);
//     if(root_node==NULL){ //tree is empty.hence we need to update our root
//         root_node=new_node;
//         return;
//     }
//     Node* current=root_node;
//     while(true){
//         if(current->value>data){
//             if(current->left==NULL){  //agar empty spot hai,toh vahi new node attach krlenge.
//                 current->left=new_node;
//                 return;
//             }
//             current=current->left; //if empty spot not presnt,we move to the left subtree.
//         }
//         else{
//             if(current->right==NULL){  
//                 current->right=new_node;
//                 return;
//             }
//             current=current->right; 
//         }
//     }
// }
// void inorder_traversal(Node* root){
//     if(root==NULL){
//         return;
//     }

//     inorder_traversal(root->left);
//     cout<<root->value<<" ";
//     inorder_traversal(root->right);
// }
// int main(){
//     Bst b1;
//     insert(b1.root,5);
//     insert(b1.root,9);
//     insert(b1.root,3);
//     insert(b1.root,4);
//     insert(b1.root,2);
//     insert(b1.root,11);
//     insert(b1.root,8);
//     inorder_traversal(b1.root);

//     return 0;
// }
    
    /*
       5
     3   9
   2  4  8  11
*/

//recursive approach;
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
    inorder_traversal(b1.root);

    return 0;
}

// #include<iostream>  //recursive approach
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
// Node* insert(Node* root_node,int data){
//      //base case
//      if(root_node==NULL){  //handle the empty tree and the empty spot for inserting the new node
//         Node* new_node=new Node(data);
//         return new_node;
//      }
      
//      //recursive case
//      if(root_node->value>data){
//         root_node->left=insert(root_node->left,data);
//      }
//      else{
//         root_node->right=insert(root_node->right,data);
//      }
//      return root_node;

// }

// bool search(Node* root_node,int key){
//     if(root_node==NULL){   //handle empty tree or the case when key is not present and we search till we reach an empty space that is NULL.
//         return false;
//     }

//     if(root_node->value==key){
//         return true;
//     }
//     bool ans;
//     if(root_node->value>key){
//         ans=search(root_node->left,key);
//     }
//     else{
//         ans=search(root_node->right,key);
//     }
//     return ans;
// } 
// int main(){
//     Bst b1;
//     b1.root=insert(b1.root,5);
//     insert(b1.root,9);
//     insert(b1.root,3);
//     insert(b1.root,4);
//     insert(b1.root,2);
//     insert(b1.root,11);
    
//     cout<<(search(b1.root,123)==1?"Yes":"NO");

//     return 0;
// }

//iterative approach
#include<iostream>  //recursive approach
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
Node* insert(Node* root_node,int data){
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

bool search(Node* root_node,int key){
    if(root_node==NULL){   //handle empty tree 
        return false;
    }

    Node* current=root_node;
    while(current!=NULL){
        if(current->value==key){
            return true;
        }
        else if(current->value>key){
            current=current->left;
        }
        else{
            current=current->right;
        }
    }
    return false;
} 
int main(){
    Bst b1;
    b1.root=insert(b1.root,5);
    insert(b1.root,9);
    insert(b1.root,3);
    insert(b1.root,4);
    insert(b1.root,2);
    insert(b1.root,11);
    
    cout<<(search(b1.root,11)==1?"Yes":"NO");

    return 0;
}
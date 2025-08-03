#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int data){
        val=data;
        left=right=NULL;
    }
};
class BST{
   Node* root;
   
public:
   BST(){
    root=NULL;
   }
   
   int insert_and_find(int value){
    int max_val=-1;
    Node* new_node=new Node(value);
    if(root==NULL){
       root=new_node;
       return max_val;
    }
    Node* curr=root;
    while(true){
       if(curr->val>value){
           max_val=curr->val;
           if(curr->left!=NULL){
              curr=curr->left;
           }
           else{
            curr->left=new_node;
            return max_val;
           }
        }
        else{
            if(curr->right!=NULL){
                curr=curr->right;
            }
            else{
                curr->right=new_node;
                return max_val;
            }
        }
    }
    return max_val;
   }

};
int main(){
    BST B;
    
    vector<int> v={5,6,7,2};
    for(int i=v.size()-1;i>=0;i--){
        v[i]=B.insert_and_find(v[i]);
    }

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
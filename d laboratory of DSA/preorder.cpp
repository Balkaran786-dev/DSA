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
void preorder_recursive(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->value<<" ";
    preorder_recursive(root->left);
    preorder_recursive(root->right);
    
}
void preorder_iterative(Node* root){
    stack<Node*> st;
    if(root==NULL)return;
    st.push(root);
    while(!st.empty()){
        Node* curr=st.top();
        st.pop();
        cout<<curr->value<<" ";
        if(curr->right!=NULL) st.push(curr->right);
        if(curr->left!=NULL) st.push(curr->left);
    }
}
int main(){
    Node* root=new Node(2);
    root->left=new Node(3);  
    root->right=new Node(4);
    root->left->left=new Node(5);
    root->left->right=new Node(6);
    root->right->left=new Node(7);
    root->right->right=new Node(8);

    cout<<"Through recursive:- "<<endl;
    preorder_recursive(root);
    cout<<endl;
    cout<<"Through iterative:- "<<endl;
    preorder_iterative(root);

    cout<<"\nBalkaran singh 23102027"<<endl;
}
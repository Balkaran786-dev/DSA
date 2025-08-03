// BFS AND DFS in BST
#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *left;
    node *right;

    node(){
        left = NULL;
        right = NULL;
    }
    node(int data){
        this->data = data ;
        left = NULL;
        right = NULL;
    }
};

void insert(node * &root ,int ele){
    if(root == NULL){
        root = new node(ele);
        return;
    }
    node *temp = new node (ele);
    node *curr = root;
    node *par;
    while(curr != NULL){
        if (curr->data == ele) break;

        else if(curr->data > ele){
            // curr->left = temp;
            par = curr;
            curr = curr->left;
        }
        else{
            // curr->right = temp;
            par = curr;
            curr = curr->right;
        }
    }
    if(par->data > ele) par->left = temp;
    else par->right = temp;
}

void recursive_inorder(node* root){
    if (root == NULL) return;
    recursive_inorder(root->left);
    cout<<root->data<<" ";
    recursive_inorder(root->right);
}

void recursive_preorder(node* root){
    if (root == NULL) return;
    cout<<root->data<<" ";
    recursive_preorder(root->left);
    recursive_preorder(root->right);
}

void recursive_postorder(node* root){
    if (root == NULL) return;
    recursive_postorder(root->left);
    recursive_postorder(root->right);
    cout<<root->data<<" ";
}


void levelorder_traversal(node *root){
    queue <node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        if (temp == NULL){
            cout<<endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";

            if (temp->left){
                q.push(temp->left);
            } 
            if (temp->right){
                q.push(temp->right);
            } 
        }
    }
}

void iterative_preorder(node* root){
    stack<node*> st;
    if(root==NULL)return;
    st.push(root);
    while(!st.empty()){
        node* curr= st.top();
        st.pop();
        cout<<curr->data<<" ";
        if(curr->right!=NULL) st.push(curr->right);
        if(curr->left!=NULL) st.push(curr->left);
    }
}

int main(){
    cout<<"Name = BASANT"<<endl<<"Roll no. = 23103028"<<endl;
    node *root = NULL;
    
    insert(root,5); 
    insert(root,2); 
    insert(root,7); 
    insert(root,3); 
    insert(root,1); 
    insert(root,6); 
    insert(root,9); 

    cout<<"Recursive traversal of tree is: "<<endl;
    cout<<"inorder traveral: ";
    recursive_inorder(root);
    cout<<"\npreorder traveral: ";
    recursive_preorder(root);
    cout<<"\npostorder traveral: ";
    recursive_postorder(root);

    cout<<endl;
    cout<<"\niterative traversal of tree is: "<<endl;
    cout<<"\npreorder traveral: ";
    iterative_preorder(root);
    cout<<"\nlevelorder traveral: "<<endl;
    levelorder_traversal(root);
}

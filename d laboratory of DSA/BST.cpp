//iterative approach

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
void insert(Node* &root_node,int data){
    Node* new_node=new Node(data);

    if(root_node==NULL){ //tree is empty.hence we need to update our root
        root_node=new_node;
        return;
    }
    Node* current=root_node;

    while(true){
        if(current->value>data){
            if(current->left==NULL){  //agar empty spot hai,toh vahi new node attach krlenge.
                current->left=new_node;
                return;
            }
            current=current->left; //if empty spot not presnt,we move to the left subtree.
        }
        else{
            if(current->right==NULL){  
                current->right=new_node;
                return;
            }
            current=current->right; 
        }
    }
}
void inorder_traversal(Node* root){
    if(root==NULL){
        return;
    }

    inorder_traversal(root->left);
    cout<<root->value<<" ";
    inorder_traversal(root->right);
}
bool if_present(Node* root,int ele){
    Node* curr=root;
    int no_of_comparisons=0;
    while(curr!=NULL){
        if(curr->value==ele){
            no_of_comparisons++;
            cout<<"No. of comparisons:- "<<no_of_comparisons<<endl;
            return true;
        }
        else if(curr->value>ele){
            no_of_comparisons++;
            curr=curr->left;
        }
        else{
            no_of_comparisons++;
            curr=curr->right;
        }
    }
    cout<<"No. of comparisons:- "<<no_of_comparisons<<endl;
    return false;
}
int main(){
    Bst b1;
    insert(b1.root,5);
    insert(b1.root,9);
    insert(b1.root,3);
    insert(b1.root,4);
    insert(b1.root,2);
    insert(b1.root,11);
    insert(b1.root,8);
    inorder_traversal(b1.root);
    int x;
    cout<<"\nEnter  the ele you wanna find:- "<<endl;
    cin>>x;
    bool res=if_present(b1.root,x);
    if(res){
        cout<<"Yes,it is present";
    }
    else{
        cout<<"No,it is not present";
    }

    cout<<"\nBalkaran singh 23102027"<<endl;

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
     char data;
     vector<Node*> children;
     
     Node(char data){
        this->data=data;
     }
};
void preorder_traversal(Node* root){
    if(root==NULL){
        return;
    }

    int childNodes=root->children.size();
    for(int i=0;i<childNodes;i++){
        preorder_traversal(root->children[i]);
    }
    cout<<root->data<<" ";
    
}
int main(){
     Node* root=new Node('A');
     root->children.push_back(new Node('B'));
     root->children.push_back(new Node('C'));
     root->children.push_back(new Node('D'));
     root->children[0]->children.push_back(new Node('E'));
     root->children[0]->children.push_back(new Node('F'));
     root->children[2]->children.push_back(new Node('G'));
     preorder_traversal(root);
    return 0;
}
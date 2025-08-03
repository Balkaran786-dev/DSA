//mein apne child node ke vector ko reverse krdunga aap baki har ek node ke child nodes ke vector ko reverse krdo.
#include<iostream>  //we can traverse in any order .
#include<vector>
#include<algorithm>
using namespace std;
class Node{
public:
     int data;
     vector<Node*> children;
     
     Node(int data){
        this->data=data;
     }
};
void mirror(Node* root){
    if(root==NULL){  //if tree is empty
        return;
    }
    if(root->children.size()<2){ //leaf node or only 1 child,no need to do anything 
        return;
    }

    reverse(root->children.begin(),root->children.end()); 
    for(Node* ele:root->children){
        mirror(ele);
    } 
}
void preorder_traversal(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    for(Node* ele:root->children){
        preorder_traversal(ele);
    }
}
int main(){                       //o(n)-time complexity  o(h)+o(h) space complexity for both function recursion stack.,where h is height of tree. 
     Node* root=new Node(10);
     root->children.push_back(new Node(2));
     root->children.push_back(new Node(34));
     root->children.push_back(new Node(56));
     root->children.push_back(new Node(100));
     root->children[1]->children.push_back(new Node(1));
     root->children[3]->children.push_back(new Node(7));
     root->children[3]->children.push_back(new Node(8));
     root->children[3]->children.push_back(new Node(9));
     preorder_traversal(root);
     cout<<"\n";
     mirror(root);
     preorder_traversal(root);
    return 0;
}
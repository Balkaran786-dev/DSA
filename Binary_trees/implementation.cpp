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
int main(){
    Node* root=new Node(2);
    root->left=new Node(3);  //directly node ke equal kardiya :)
    root->right=new Node(4);

    cout<<"root node-"<<root->value<<endl;
    cout<<"left child-"<<root->left->value<<endl;
    cout<<"right child-"<<root->right->value<<endl;
}
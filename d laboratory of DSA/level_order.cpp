#include<iostream>
#include<queue>
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

void levelorder_traversal_recursive(queue<Node*> &qu){
    if(qu.empty()){
        return;
    }

    int no_of_nodes=qu.size();
    while(no_of_nodes--){
        Node* curr=qu.front();
        qu.pop();
        cout<<curr->value<<" ";
        if(curr->left!=NULL) qu.push(curr->left);
        if(curr->right!=NULL) qu.push(curr->right);
    }
    
    levelorder_traversal_recursive(qu);
}

void levelorder_traversal_iterative(Node* root_node){
     if(root_node==NULL){  
        return;
     }
     queue<Node*> qu; 
     qu.push(root_node); 
     while(!qu.empty()){
        int nodes_at_curr_level=qu.size();
        while(nodes_at_curr_level!=0){
            Node* curr_node=qu.front();
            qu.pop();
            cout<<curr_node->value<<" ";

            if(curr_node->left){
                qu.push(curr_node->left);
            }
            if(curr_node->right){
                qu.push(curr_node->right);
            }
            nodes_at_curr_level--;
        }
     }
}
int main(){
    Node* root=new Node(2);
    root->left=new Node(4);
    root->right=new Node(10);
    root->left->left=new Node(6);
    root->left->right=new Node(5);
    root->right->right=new Node(11);
    queue<Node*> qu;
    if(root!=NULL) qu.push(root);
    cout<<"Through recursion: "<<endl;
    levelorder_traversal_recursive(qu);
    cout<<"\nThrough iterative: "<<endl;
    levelorder_traversal_iterative(root);
    cout<<"\nBalkaran singh 23102027"<<endl;

    return 0;
}


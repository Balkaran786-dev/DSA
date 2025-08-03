#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
public:
     char data;
     vector<Node*> children;
     
     Node(char data){
        this->data=data;
     }
};
void levelorder_traversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> qu;
    qu.push(root);

    while(!qu.empty()){
        int nodes_at_level=qu.size();
        while(nodes_at_level--){
            Node* curr_node=qu.front();
            qu.pop();

            cout<<curr_node->data<<" ";
            for(auto ele:curr_node->children){
                qu.push(ele);
            }
        }
        cout<<"\n";
    }
}
int main(){
     Node* root=new Node('A');
     root->children.push_back(new Node('B'));
     root->children.push_back(new Node('C'));
     root->children.push_back(new Node('D'));
     root->children[0]->children.push_back(new Node('E'));
     root->children[0]->children.push_back(new Node('F'));
     root->children[2]->children.push_back(new Node('G'));
     levelorder_traversal(root);
    return 0;
}
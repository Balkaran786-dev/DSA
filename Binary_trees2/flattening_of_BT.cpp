#include<iostream>    //o(n)-time and space complexity.
#include<unordered_map>
#include<vector>
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
void levelorder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> qu;
    qu.push(root);
    while(!qu.empty()){
        int nodes_at_level=qu.size();
        while(nodes_at_level!=0){
            Node* curr_node=qu.front();
            qu.pop();
            cout<<curr_node->value<<" ";   //printing the curr_node
            if(curr_node->left){            //inserting the left child if present
                qu.push(curr_node->left);
            }
            if(curr_node->right){           //inserting the right child if present
                qu.push(curr_node->right);
            }
            nodes_at_level--;
        }
        cout<<"\n";
    }
}
void flatten_tree(Node* &root_node,Node* &last){
      if(root_node==NULL){
        return;
      }

      flatten_tree(root_node->right,last);
      flatten_tree(root_node->left,last);
      root_node->left=NULL;
      root_node->right=last;
      last=root_node;
      return;

}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    root->right->right=new Node(6);
    Node* last=NULL;
    flatten_tree(root,last);
    levelorder(root);
    return 0;
}
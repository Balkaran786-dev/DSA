#include<iostream>
#include<queue>
#include<vector>
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
vector<int> levelorder_traversal(Node* root_node){
     vector<int> ans;
     if(root_node==NULL){  //may be the tree is already empty
        return ans;
     }

     queue<Node*> qu;
     qu.push(root_node);
     
     while(!qu.empty()){
        int nodes_at_curr_level=qu.size();
        int a=qu.size();
        while(nodes_at_curr_level){
            Node* curr_node=qu.front();

            if(curr_node->left){
                qu.push(curr_node->left);
            }
            if(curr_node->right){
                qu.push(curr_node->right);
            }
            if(nodes_at_curr_level==a){  //we reach the last element of a specific level.
                ans.push_back(curr_node->value);
            }
            qu.pop();
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
    root->left->right->right=new Node(12);
    root->right->right=new Node(11);
    vector<int> leftmostnodes=levelorder_traversal(root);
    for(auto ele:leftmostnodes){
        cout<<ele<<" ";
    }
    return 0;
}


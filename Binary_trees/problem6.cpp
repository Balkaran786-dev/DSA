#include<iostream>
#include<queue>
#include<stack>
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
void reverse_level_order(Node* root_node){
     stack<int> st;
     if(root_node==NULL){  //may be the tree is already empty
        return;
     }

     queue<Node*> qu;
     qu.push(root_node);
     while(!qu.empty()){
        int nodes_at_curr_level=qu.size();
        while(nodes_at_curr_level!=0){
            Node* curr_node=qu.front();
            qu.pop();
            if(curr_node->right){
                qu.push(curr_node->right);
            }
             if(curr_node->left){
                qu.push(curr_node->left);
            }
            st.push(curr_node->value);
            nodes_at_curr_level--;
        }
     }

     while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
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
    reverse_level_order(root);
    
    return 0;
}

/*
     2
   4   10
 6   5    11
       12
*/

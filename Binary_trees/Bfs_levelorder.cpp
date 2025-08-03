#include<iostream>  //mine way
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
void levelorder_traversal(queue<Node*> &qu){
    if(qu.empty()){
        return;
    }

    int size=qu.size();
    while(size--){
        Node* curr_node=qu.front();
        qu.pop();
        cout<<curr_node->value<<" ";
        if(curr_node->left!=NULL){
            qu.push(curr_node->left);
        }
        if(curr_node->right!=NULL){
            qu.push(curr_node->right);
        }
    }
    cout<<endl;
    levelorder_traversal(qu);
}
int main(){
    Node* root=new Node(2);
    root->left=new Node(4);
    root->right=new Node(10);
    root->left->left=new Node(6);
    root->left->right=new Node(5);
    root->right->right=new Node(11);
    queue<Node*> qu;
    qu.push(root);
    levelorder_traversal(qu);
    return 0;
}

// /*
//      2
//    4   10
//   6 5    11

// */


//in above case,we r not able to print the exact level wise ele


// #include<iostream>
// #include<queue>
// using namespace std;
// class Node{
// public:
//      int value;
//      Node* left;
//      Node* right;

//      Node(int val){
//        value=val;
//        left=right=NULL;
//      }
// };

// void levelorder_traversal(Node* root_node){
//      if(root_node==NULL){  //may be the tree is already empty
//         return;
//      }

//      queue<Node*> qu; //to store the left and right child nodes in order
//      qu.push(root_node); //first root node ko pehle hi push kardenge.
     
//      while(!qu.empty()){
//         int nodes_at_curr_level=qu.size();
//         while(nodes_at_curr_level!=0){
//             Node* curr_node=qu.front();
//             qu.pop();
//             cout<<curr_node->value<<" ";

//             if(curr_node->left){
//                 qu.push(curr_node->left);
//             }
//             if(curr_node->right){
//                 qu.push(curr_node->right);
//             }
//             nodes_at_curr_level--;
//         }
//         cout<<"\n";
//      }
// }
// int main(){
//     Node* root=new Node(2);
//     root->left=new Node(4);
//     root->right=new Node(10);
//     root->left->left=new Node(6);
//     root->left->right=new Node(5);
//     root->right->right=new Node(11);
//     levelorder_traversal(root);
//     return 0;
// }


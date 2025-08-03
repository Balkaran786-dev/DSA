#include<iostream>
#include<queue>
#include<vector>
#include<map>
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

     queue<pair<Node*,int>> qu;  //we are storing a pair of node and its column
     qu.push(make_pair(root_node,0));
     map<int,int> m;  //here we store column as key and node value as value.
     
     while(!qu.empty()){

        int nodes_at_curr_level=qu.size();

        while(nodes_at_curr_level!=0){

            pair<Node*,int> curr=qu.front();
            qu.pop();

            if(m.find(curr.second)==m.end()){
                 m[curr.second]=curr.first->value;
            }

            if(curr.first->left){
                qu.push(make_pair(curr.first->left,curr.second-1));
            }
            if(curr.first->right){
                qu.push(make_pair(curr.first->right,curr.second+1));
            }
            
            nodes_at_curr_level--;
            
        }
     }
     for(auto ele:m){
        ans.push_back(ele.second);
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
    vector<int> rightmostnodes=levelorder_traversal(root);
    for(auto ele:rightmostnodes){
        cout<<ele<<" ";
    }
    return 0;
}

//In BST,if we know the preorder traversal,
//then it is easy to know whether it will go to 
//left or right subtree. we can use our own insert function
//to insert nodes one by one...
#include<bits/stdc++.h>  //given on leetcode
using namespace std;
class TreeNode{
public:
     int val;
     TreeNode* left;
     TreeNode* right;
     
     TreeNode(){
        this->val=0;
       left=right=NULL;
     }
     TreeNode(int val){
       this->val=val;
       left=right=NULL;
     }

};
void insert(TreeNode* &root_node,int data){
    TreeNode* new_node=new TreeNode(data);
    if(root_node==NULL){ //tree is empty.hence we need to update our root
        root_node=new_node;
        return ;
    }
    TreeNode* current=root_node;
    while(true){
        if(current->val>data){
            if(current->left==NULL){  //agar empty spot hai,toh vahi new node attach krlenge.
                current->left=new_node;
                return;
            }
            current=current->left; //if empty spot not presnt,we move to the left subtree.
        }
        else{
            if(current->right==NULL){  
                current->right=new_node;
                return;
            }
            current=current->right; 
        }
    }
}
class Codec {
public:
    void  serialize_helper(TreeNode* root,string &str){
        if(root==NULL) return;

        string node=to_string(root->val);
        str.append(node);
        str.append(",");

        serialize_helper(root->left,str);
        serialize_helper(root->right,str);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str="";
        serialize_helper(root,str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        int i=0;  //to traverse the string
        int break_pos=data.find(",");
        string root=data.substr(0,break_pos);
        TreeNode* root_node=new TreeNode(stoi(root));
        i=break_pos+1;
        while(i<data.size()){

            break_pos=data.find(",",i);
            string node=data.substr(i,break_pos-i);
            insert(root_node,stoi(node));
            i=break_pos+1;

        }
        return root_node;
    }
};

void preorder_traversal(TreeNode* root_node){
    if(root_node==NULL){
        return;
    }
    cout<<root_node->val<<" ";
    preorder_traversal(root_node->left);
    preorder_traversal(root_node->right);
}
int main(){
    Codec c;
    TreeNode* root=new TreeNode(5);
    insert(root,3);
    insert(root,2);
    insert(root,1);
    insert(root,4);
    insert(root,10);
    insert(root,8);
    insert(root,6);
    insert(root,7);
    preorder_traversal(root);
    cout<<endl;
    string val=c.serialize(root);
    cout<<val<<endl;
    TreeNode* new_root=c.deserialize(val);
    preorder_traversal(new_root);
}
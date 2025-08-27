/*In Binary tree,if we have a preoder traversal,we won't be able to guess
whether the node will be in left or right subtree,but if we have level order 
it will be easy for us to detect.Also at place  of NULL we can insert "#" or anything
else to just remind us that if it comes,that means there is an empty spot ,so we do that child as NULL,
In n-arry,we can't use level order,beacuse we don't know ek node ke kitne child ho skte hain
,we need to store how many child nodes it has,so our urvi's approach is okay for that,there we did preoder with urvi.
## str.find(substring,i): to find subtring first occurence in str from ith index.
## str.substr(i,L): to create subtring of str from ith index of length L,including that ith index character also.
*/
#include<bits/stdc++.h>  //given on leetcode
using namespace std;
class TreeNode{
public:
     int val;
     TreeNode* left;
     TreeNode* right;

     TreeNode(int val){
       this->val=val;
       left=right=NULL;
     }

};
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str="";
        queue<TreeNode*> qu;
        if(!root) return str;
        qu.push(root);     
        while(!qu.empty()){
            int nodes_at_same_level=qu.size();
            while(nodes_at_same_level--){
                TreeNode* node=qu.front();
                qu.pop();
                if(node==NULL){
                    str.append("#,");  //to mark that there is an empty spot there.
                    continue;
                }
                str.append(to_string(node->val));
                str.append(",");
                qu.push(node->left);
                qu.push(node->right);
            }
        }
        return str;
    }
    
    TreeNode* deserialize(string data) {

        if(data.empty()) return NULL;
        int break_pos1=data.find(",");

        string root=data.substr(0,break_pos1);

        TreeNode* root_node=new TreeNode(stoi(root));  //pehle root node bna lenge taki ese hum queue mein da ske
        queue<TreeNode*> qu;

        qu.push(root_node); 
        int i=break_pos1+1;  //yeh i ko move krna is important tabhi toh hum find ko bta payenge ki i ko baad 
                               //se find kro "," nhi toh voh pehle "," ko hi find krta rhega and uska index baar baar return krta rhega
        while(!qu.empty()){
           int nodes_at_same_level=qu.size();
           while(nodes_at_same_level--){
              TreeNode* node=qu.front();
              qu.pop();

              //leftchild
              int break_pos2=data.find(",",i);
              string left_child=data.substr(i,break_pos2-i);
              i=break_pos2+1;  //yeh i ko move krna is important tabhi toh hum find ko bta payenge ki i ko baad 
                               //se find kro "," nhi toh voh pehle "," ko hi find krta rhega and uska index baar baar return krta rhega
              if(left_child=="#"){
                node->left=NULL;
              }
              else{
                TreeNode* node1=new TreeNode(stoi(left_child));
                node->left=node1;
                qu.push(node1);
              }
              
              //right child
              break_pos2=data.find(",",i);
              string right_child=data.substr(i,break_pos2-i);
              i=break_pos2+1;         
              if(right_child=="#"){
                node->right=NULL;
              }
              else{
                TreeNode* node2=new TreeNode(stoi(right_child));
                node->right=node2;
                qu.push(node2);
              }
           }
        }
        return root_node;
    }
};
void levelorder_traversal(TreeNode* root){
    if(root==NULL){
        return;
    }
    queue<TreeNode*> qu;
    qu.push(root);

    while(!qu.empty()){
        int nodes_at_level=qu.size();
        while(nodes_at_level--){
            TreeNode* curr_node=qu.front();
            qu.pop();

            cout<<curr_node->val<<" ";
            if(curr_node->left){
                qu.push(curr_node->left);
            }
            if(curr_node->right){
                qu.push(curr_node->right);
            }
        }
        cout<<"\n";
    }
}

int main(){
    Codec c;
    TreeNode* root=new TreeNode(2);
    root->left=new TreeNode(4);
    root->right=new TreeNode(10);
    root->left->left=new TreeNode(6);
    root->left->right=new TreeNode(5);
    root->right->right=new TreeNode(11);
    levelorder_traversal(root);
    string val=c.serialize(root);
    cout<<val<<endl;
    TreeNode* new_root=c.deserialize(val);
    cout<<endl;
    levelorder_traversal(new_root);

}
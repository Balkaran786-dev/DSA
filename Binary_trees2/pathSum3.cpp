//bruteforce approach
#include<iostream>  //o(n**2)- time complexity   o(1)- space complexity
using namespace std;
int path=0; //global variable
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
void FindSumhelper(Node* &root_node,int target_sum,int curr_sum){  //acting as an inner loop
     if(root_node==NULL){
       return;
     }
     curr_sum+=root_node->value;
     if(curr_sum==target_sum){
      path+=1;
     }
     FindSumhelper(root_node->left,target_sum,curr_sum);
     FindSumhelper(root_node->right,target_sum,curr_sum);
     curr_sum=curr_sum-root_node->value;  //while backtracking.
}
void total_path(Node* &root_node,int target_sum){ //acting an an outer loop
     //dfs(preoreder) manner mein ek ek node ko curr_node bnakar,usse aage ke child nodes ke sath sum calculate kar rha hu.
      if(root_node==NULL){  
        return;
      }
      FindSumhelper(root_node,target_sum,0); //0 is basically curr_sum har ek diff node se jab start krenge toh curr_sum toh zero lekar chlenge.
      total_path(root_node->left,target_sum);
      total_path(root_node->right,target_sum);
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(-3);
    root->left->left=new Node(3);
    root->left->right=new Node(2);
    root->left->left->left=new Node(3);
    root->left->left->right=new Node(-2);
    root->left->left->right->left=new Node(7);
    root->left->right->right=new Node(1);
    root->right->right=new Node(11);
    int target_sum=8;
    total_path(root,target_sum);
    cout<<path;
    return 0;
}

/*
        10
      5     -3
    3   2       11
  3 -2     1
       7

*/

//we need to traverse in dfs preorder manner.because that will basically create the path
#include<iostream>    //o(n)-time and space complexity.
#include<unordered_map>
using namespace std;
int path=0; //global variable
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
void pathSumhelper(Node* root,int target,int curr_sum,unordered_map<int,int> pathcount){

     if(root==NULL){
      return;
     }

     curr_sum+=root->value; 
     if(pathcount.find(curr_sum-target)!=pathcount.end()){
          path+=pathcount[curr_sum-target]; //adding the frequency to the path
     }

     pathcount[curr_sum]++;  //inserting curr sum in map
     pathSumhelper(root->left,target,curr_sum,pathcount);
     pathSumhelper(root->right,target,curr_sum,pathcount);
     pathcount[curr_sum]--;  //while backtracking,deducing curr_sum from map

}
void pathSum(Node* root_node,int target_sum){
     unordered_map< int,int> pathcount;
     pathcount[0]=1; //initilising our map with one standard value..may be our root of the tree is 
                     //already equal to the target sum.so,8-8=0 0 should be present in the map in the starting.
     pathSumhelper(root_node,target_sum,0,pathcount);
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(-3);
    root->left->left=new Node(3);
    root->left->right=new Node(2);
    root->left->left->left=new Node(3);
    root->left->left->right=new Node(-2);
    root->left->left->right->left=new Node(7);
    root->left->right->right=new Node(1);
    root->right->right=new Node(11);
    int target_sum=8;
    pathSum(root,target_sum);
    cout<<path;
    return 0;
}
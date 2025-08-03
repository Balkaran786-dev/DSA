#include<iostream>  //we can traverse in any order
#include<vector>
using namespace std;
class Node{
public:
     int data;
     vector<Node*> children;
     
     Node(int data){
        this->data=data;
     }
};
// void just_greater_ele(Node* root,int ele,int &ans){
//     if(root==NULL){
//         return;
//     }

//     if(root->data<ans && root->data>ele){ //updating my ans
//         ans=root->data;
//     }
//     for(Node* element:root->children){ 
//         just_greater_ele(element,ele,ans);
//     }
// }
void just_greater_ele(Node* root,int ele,int& ans){
    if(root==NULL)return;

    if(root->data>ele){
        ans=min(ans,root->data);
    }
    for(int i=0;i<root->children.size();i++){
          just_greater_ele(root->children[i],ele,ans);
    }
    
 }
int main(){
     Node* root=new Node(20);
     root->children.push_back(new Node(8));
     root->children.push_back(new Node(22));
     root->children[0]->children.push_back(new Node(4));
     root->children[0]->children.push_back(new Node(12));
     root->children[0]->children[1]->children.push_back(new Node(10));
     root->children[0]->children[1]->children.push_back(new Node(14));
     int ele=4;
     int ans=INT16_MAX;
     just_greater_ele(root,ele,ans);
     (ans==INT16_MAX? cout<<"NULL":cout<<ans);
    return 0;
}
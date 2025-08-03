#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
class Node{
public:
     int data;
     vector<Node*> children;
     
     Node(int data){
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
// void serialising(Node* root,string &ans){
//        if(root==NULL){
//           return;
//        }
       
//        ans+=to_string(root->data)+":"+to_string(root->children.size())+":";
//        for(Node* child:root->children){
//            ans+=to_string(child->data)+",";
//        }
//        if(root->children.size())ans.pop_back();  //to remove the extra , after the childs
//        ans+="\n";
//        for(Node* child:root->children){    //preorder traversal kar rhe hein
//            serialising(child,ans);
//        }
// }
// Node* desiralisedTreeHelper(int curr_node_value,unordered_map<int,string> m){
//        Node* node=new Node(curr_node_value);
  
//        string nodestr=m[curr_node_value];
  
//        if(nodestr[0]=='0'){  //leaf node
//         return node;
//        }

//        int breakpos=nodestr.find(':');
//        int total_childs=stoi(nodestr.substr(0,breakpos));
//        string childNodes_str=nodestr.substr(breakpos+1); //sirf child nodes vala part
       
//        int start=0;
//        for(int i=0;i<total_childs;i++){  
//            int end=childNodes_str.find(',',start);
//            if(end==string::npos) end=childNodes_str.size(); //for last child,we won't have ',' so in that case hum currnodeprop ke size ke equal end krdenge.that means last character se ek aage location pe.
//             //string::npos is used if find fuction is not able to find the specified character.     
//            int child_node_value=stoi(childNodes_str.substr(start,end));
//            node->children.push_back(desiralisedTreeHelper(child_node_value,m));
//            start=end+1;
//        }
//        return node;
// }
// Node* deserialisedtree(string s){
//     if(s==""){
//         return NULL;
//     }
//     unordered_map<int,string> m;
//     int start=0;
//     for(int i=0;i<s.size();i++){
//         if(s[i]=='\n'){
//             string single_node_str=s.substr(start,i-start); 
//             int breakpos=single_node_str.find(':');
//             int nodevalue=stoi(single_node_str.substr(0,breakpos));
//             m[nodevalue]=single_node_str.substr(breakpos+1);
//             start+=i+1;
//         }
//     }
//     int rootNodeValue=stoi(s.substr(0,s.find(':')));
//     return desiralisedTreeHelper(rootNodeValue,m);
// }

void serialising(Node* root,string &serialisedTree){
    if(root==NULL) return;

    string ans="";
    ans+=(to_string(root->data));
    ans.push_back(':');
    int childs=root->children.size();
    ans.push_back(childs+'0');
    ans.push_back(':');

    for(int i=0;i<childs;i++){
        ans+=to_string(root->children[i]->data);
        ans.push_back(',');
    }
    if(childs>0) ans.pop_back();
    ans+="\n";
    serialisedTree+=ans;
    for(int i=0;i<childs;i++){
        serialising(root->children[i],serialisedTree);
    }
}
void deserialising(Node* &root,unordered_map<string,string> mp,string root_val){

    string info=mp[root_val];
    int start_pos=info.find(":")+1; //for child nodes
    string num=info.substr(0,start_pos);
    int childs=stoi(num);
    if(childs==0) return;
    int break_pos1;
    while(childs){
        string child_node;
        if(childs==1){
            child_node=info.substr(start_pos,info.size()-start_pos);
        }
        else{
            break_pos1=info.find(",",start_pos);
            child_node=info.substr(start_pos,break_pos1-start_pos);
            start_pos=break_pos1+1;
        }
        childs--;
        Node* child=new Node(stoi(child_node));
        root->children.push_back(child);
    }

    for(auto neigh:root->children){
       deserialising(neigh,mp,to_string(neigh->data));
    }

}
Node* deserialisedtree(string str){
    unordered_map<string,string> mp;
    if(str.size()==0){
        return NULL;
    }
    
    string root;
    bool flag=true;
    while(!str.empty()){
        int start_pos=0;
        int break_pos1=str.find(":");
        int break_pos2=str.find("\n");
        string curr_node=str.substr(start_pos,break_pos1-start_pos);
        if(flag) root=curr_node;
        string info=str.substr(break_pos1+1,break_pos2-break_pos1-1);
        mp[curr_node]=info;
        str.erase(str.begin(),str.begin()+break_pos2+1);
        flag=false;
    }
    for(auto ele:mp){
        cout<<ele.first<<":"<<ele.second<<endl;
    }
    Node* root_node=new Node(stoi(root));
    deserialising(root_node,mp,root);
    return root_node;
}
int main(){                       
     Node* root=new Node(10);
     root->children.push_back(new Node(2));
     root->children.push_back(new Node(34));
     root->children.push_back(new Node(56));
     root->children.push_back(new Node(100));
     root->children[1]->children.push_back(new Node(1));
     root->children[3]->children.push_back(new Node(7));
     root->children[3]->children.push_back(new Node(8));
     root->children[3]->children.push_back(new Node(9));
     levelorder_traversal(root);
     cout<<"\n\n";
     string serialisedTree="";
     serialising(root,serialisedTree);
     cout<<serialisedTree<<" \n\n";
     Node* deserialised_root=deserialisedtree(serialisedTree);
     levelorder_traversal(deserialised_root);
    return 0;
}

/*
           10
    2   34    56   100
         1         7 8 9 
    
*/
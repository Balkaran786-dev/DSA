#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
   int val;
   Node* next;
   Node* prev;

   Node(int value){
    val=value;
    prev=NULL;
    next=NULL;
   }
};

class doubly_linked_list{
public: 
    Node* head;
    Node* tail;

    doubly_linked_list(){
        head=NULL;
        tail=NULL;
    }

    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }cout<<endl;
    }

    void insert_at_tail(int val){
        Node* new_node=new Node(val);
        if(tail==NULL){
            head=new_node;
            tail=new_node;
            return;
        }

        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
    }

};
bool isCriticalpt(Node* curr_node){  //to check if the curr_node is a critical point or not
    if(curr_node->next->val>curr_node->val && curr_node->prev->val>curr_node->val){ //local minima
        return true;
    }
    if(curr_node->next->val<curr_node->val && curr_node->prev->val<curr_node->val){  //local maxima
        return true;
    }

    return false;
}

vector<int> distance_Between_Critical_pts(Node* tail){

      vector<int> ans(2,INT16_MAX);
      Node* curr_node=tail->prev;
      int firstCp=-1, lastCp=-1;
      int curr_pos=0;
      while(curr_node->prev!=NULL){
         if(isCriticalpt(curr_node)){
            if(firstCp==-1){
                firstCp=lastCp=curr_pos;
            }
            else{
                ans[0]=min(ans[0],curr_pos-lastCp);  //min dist
                ans[1]=curr_pos-firstCp;  //max dist
                lastCp=curr_pos;
            }
         }
         curr_pos++;
         curr_node=curr_node->prev;
      }

      if(ans[0]==INT16_MAX){
        ans[0]=ans[1]=-1;
      }

      return ans;
}

/// see your own solution at leetcode ********  mindist and max dist between critical pounts 
int main(){
    doubly_linked_list dll;
    dll.insert_at_tail(1);
    dll.insert_at_tail(4); //cp
    dll.insert_at_tail(3); 
    dll.insert_at_tail(2); //cp
    dll.insert_at_tail(6);//cp
    dll.insert_at_tail(5);
    dll.display();
    vector<int> v;
    v=distance_Between_Critical_pts(dll.tail);
    cout<<v[0]<<" "<<v[1];
    
}
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
vector<int> target_sum(Node* head,Node* tail,int x){
     vector<int> ans(2,-1);
     while(head!=tail){
        int sum=head->val + tail->val;
        if(sum==x){
            ans[0]=head->val;
            ans[1]=tail->val; 
            return ans;       
        }
        else if(sum>x){   //i want to decrease my sum,i need to move tail back
            tail=tail->prev;
        }
        else{             //i want to increase my sum,i need to move head forward
            head=head->next;
        }
     }
     return ans;
}
int main(){
    doubly_linked_list dll;
    dll.insert_at_tail(2);
    dll.insert_at_tail(5); 
    dll.insert_at_tail(6); 
    dll.insert_at_tail(8); 
    dll.insert_at_tail(10);
    dll.display();
    int x;
    cout<<"Give the value of x:";
    cin>>x;
    vector<int> v;
    v=target_sum(dll.head,dll.tail,x);
    cout<<v[0]<<" "<<v[1];
    
}
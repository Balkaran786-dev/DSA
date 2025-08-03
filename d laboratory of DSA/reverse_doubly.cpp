#include<iostream>
using namespace std;
class Node{
public:
   int val;
   Node* next;
   Node* prev;

   Node(int value){
    val=value;
    next=NULL;
    prev=NULL;
   }
};
class Doubly_linked_list{
public:
    Node* head;
    Node* tail;

    Doubly_linked_list(){
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
    void insert_at_end(int val){
        Node* new_node=new Node(val);
        if(tail==NULL){  //empty
            head=new_node;
            tail=new_node;
            return;
        }
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
        return;
    }
};
Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* temp=NULL;
    while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        curr->prev=temp;
        prev=curr;
        curr=temp;
    }
    return prev;
} 
int main(){
    Doubly_linked_list dl;
    dl.insert_at_end(1);
    dl.insert_at_end(2);
    dl.insert_at_end(3);
    dl.insert_at_end(4);
    
    dl.display();

    dl.head=reverse(dl.head);
    dl.display();

    cout<<"\nName: Balkaran singh\nRollNo: 23103027\n"; 
    return 0;
}








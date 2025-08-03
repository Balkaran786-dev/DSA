#include<bits/stdc++.h>
using namespace std;
class Node{
 public:
    int data;
    Node* next;

    Node(int data){
       this->data=data;
       next=NULL;
    }
};
void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

    return;
}
void insert_at_start(Node *&head,int value){
    Node* new_node=new Node(value);
    if(head==NULL){
        head=new_node;
        return;
    }
    new_node->next=head;
    head=new_node;
    return;
}
void insert_at_end(Node* &head,int value){
    Node* new_node=new Node(value);
    if(head==NULL){
        insert_at_start(head,value);
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;

}
void give_centre_ele(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"The value of node present at centre is:- "<<slow->data<<endl;
}
int main(){
    Node* head=NULL;
    insert_at_end(head,1);
    insert_at_end(head,2);
    insert_at_end(head,3);
    insert_at_end(head,4);
    insert_at_end(head,5);
    display(head);
    give_centre_ele(head);
    insert_at_end(head,6);
    insert_at_end(head,7);
    insert_at_end(head,8);
    display(head);
    give_centre_ele(head);
    return 0;
}
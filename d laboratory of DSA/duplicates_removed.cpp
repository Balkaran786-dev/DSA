#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
   
    Node(int value){
        this->data=value;
        next=NULL;
    }
};
class LinkedList{
     public:
     Node* head;

     LinkedList(){
        head=NULL;
     }

     void insertion(int val){
        Node* new_node=new Node( val);
        if(head==NULL){
            head=new_node;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
        return;
     }

     
     void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
     }
};
void Deletion(Node* &temp1){
        if(temp1==NULL){
            return;
        }
        Node* temp2=temp1->next;
        temp1->next=temp2->next;
        free(temp2);
}
void remove_duplicates(Node* head){
    Node* temp1=head;
    while(temp1!=NULL){
        while(temp1->next!=NULL && temp1->next->data==temp1->data){
            Deletion(temp1);
        }
        temp1=temp1->next;
    }
}
int main(){
    LinkedList ll;
    ll.insertion(1);
    ll.insertion(2);
    ll.insertion(2);
    ll.insertion(3);
    ll.insertion(3);
    ll.insertion(4);
    ll.display();
    remove_duplicates(ll.head);
    ll.display();
    return 0;
}
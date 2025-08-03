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
        if(tail==NULL){
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
Node* delete_if_same_neigh(Node* tail){
    Node* curr=tail->prev;
    while(curr->prev!=NULL){
        if(curr->next->val==curr->prev->val){
            Node* new_ptr=curr->prev;
            curr->next->prev=curr->prev;
            curr->prev->next=curr->next;
            free(curr);
            curr=new_ptr;
        }
        else{
            curr=curr->prev;
        }
    }
    //now curr is pointing to the first node of the linked list
    return curr;
}
int main(){
     Doubly_linked_list dll;
     dll.insert_at_end(2);
     dll.insert_at_end(1);
     dll.insert_at_end(1);
     dll.insert_at_end(2);
     dll.insert_at_end(1);
    //  dll.insert_at_end(1);
     dll.display();
     dll.head=delete_if_same_neigh(dll.tail);
     dll.display();
     return 0;
}
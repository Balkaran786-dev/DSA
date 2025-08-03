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
bool is_palindrome(Node* head,Node* tail){

    while(head!=tail && tail->next!=head){  //first cond gets false in case of odd number of nodes
                                           //second cond fails in case of even nodes
        if(tail->val!=head->val){
            return false;
        }
        else{
            tail=tail->prev;
            head=head->next;
        }
    }
    return true;
}
int main(){
     Doubly_linked_list dll;
     dll.insert_at_end(1);
     dll.insert_at_end(2);
     dll.insert_at_end(3);
     dll.insert_at_end(3);
     dll.insert_at_end(2);
     dll.insert_at_end(1);
     dll.display();
     cout<<is_palindrome(dll.head,dll.tail);
     return 0;
}
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
// Node* reverse(Node* head,Node* tail){
//      Node* prev=NULL;
//      Node* curr=head;
//      while(curr!=NULL){
//         Node* temp=curr->next;
//         curr->next=prev;
//         curr->prev=temp;
//         prev=curr;
//         curr=temp;
//      }
//      return prev;
// }


//recursive approach
Node* reverse(Node* curr,Node* prev){
    if(curr==NULL){
        return prev;
    }
    Node* temp=curr->next;
    curr->next=prev;
    curr->prev=temp;
    return reverse(temp,curr);
}
int main(){
     Doubly_linked_list dll;
     dll.insert_at_end(1);
     dll.insert_at_end(2);
     dll.insert_at_end(3);
     dll.insert_at_end(4);
     dll.insert_at_end(5);
     dll.insert_at_end(6);
     dll.display();
     dll.head=reverse(dll.head,NULL);
     dll.display();
}
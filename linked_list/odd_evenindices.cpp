#include<iostream>  
using namespace std;
class Node{
public:
    int val;
    Node* next;

    Node(int value){
        val=value;
        next=NULL;
    }
};
class LinkedList{
public:
    Node* head;

    LinkedList(){
        head=NULL;
    }

    void insert(int val){
        Node* new_node=new Node(val);
        if(head==NULL){
            head=new_node;
            return;
        }
        Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

};
void odd_followed_by_evenindices(Node* &head){
    Node* even_head=head->next;
    Node* odd_ptr=head;
    Node* even_ptr=even_head;

    while(odd_ptr->next!=NULL && odd_ptr->next->next!=NULL){
        
        odd_ptr->next=odd_ptr->next->next;   //first do the alteration in odd ptr only,otherwise if you 
                                             //do first in even,you lose the location of next to next node.
        even_ptr->next=even_ptr->next->next;
        even_ptr=even_ptr->next;
        odd_ptr=odd_ptr->next;
    }
    odd_ptr->next=even_head;
}
int main(){
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.display();
    odd_followed_by_evenindices(ll.head);
    ll.display();
    return 0;
}

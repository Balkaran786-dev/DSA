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
bool if_plaindrome(Node* head){

    //find middle node;
    Node* slow=head;
    Node* fast=head;

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    //break the linked list in between;
    Node* prev = slow;
    Node* curr=slow->next;
    slow->next=NULL;
   
    //reverse the second half of the linked list

    Node* temp;
    while(curr){
       temp=curr->next;
       curr->next=prev;
       prev=curr;
       curr=temp;
    }
    
    //start comparing both the linked lists.
    Node* head1=head;
    Node* head2=prev;
    while(head2){
        if(head1->val!=head2->val){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    
    return true;
}
int main(){
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(2);
    ll.insert(1);
    ll.display();
    cout<<if_plaindrome(ll.head);
    return 0;
}
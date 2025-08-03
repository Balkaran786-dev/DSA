//slow-fast pointer approach
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
Node* middle_node(Node* head){
    //creating two pointers.
    Node *ptr1=head,*ptr2=head;
    //ptr1 is a slow pointer,ptr2 is a fast pointer
    while(ptr2!=NULL &&ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
    }
    return ptr1;
}
int main(){
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.insert(6);
    ll.display();
    Node* mid_node=middle_node(ll.head);
    cout<<mid_node->val;
}

#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int value){
        val=value;
    }
};
void insertion_at_head(Node* &head,int val){
    Node* new_node= new Node(val);
    new_node->next=head;
    head=new_node;
}

void insertion_at_tail(Node* &head,int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    //we don't need to point new node to null as it is already doing that because of constructor.
}
void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    Node* head=NULL;

    insertion_at_head(head,3);
    display(head);
    insertion_at_head(head,2);
    display(head);
    insertion_at_head(head,1);
    display(head);
    insertion_at_tail(head,4);
    display(head);

    return 0;
}
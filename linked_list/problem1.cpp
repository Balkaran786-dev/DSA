#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node *next;

    Node(int data){
       val=data;
       next=NULL;
    }
};
class LinkedList{
public: 
     Node* head;

    LinkedList(){  //if just initalise a linked list,it will be empty.hence head points to NUll
        head=NULL;
    }

     void insert(int value){
        Node* new_node=new Node(value);
        if(head==NULL){
            head=new_node;
            return;
        }

        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
     }

     void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
     }
    
};
void alternate_deletion(Node* head){
      Node*prev=head;
      while(prev!=NULL && prev->next!=NULL){
        Node*temp=prev->next; //this is the node to be deleted.
        prev->next=prev->next->next;
        free(temp);
        prev=prev->next;
      }
}
int main(){
     LinkedList ll;
     ll.insert(1);
     ll.insert(2);
     ll.insert(3);
     ll.insert(4);
     ll.insert(5);
     ll.display();
     alternate_deletion(ll.head);
     ll.display();

    return 0;
}


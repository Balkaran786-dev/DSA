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
class circular_linked_list{
    public:
    Node* head;

    circular_linked_list(){
        head=NULL;
    }

    void display(){
        Node* temp=head;
        do{
           cout<<temp->val<<"->";
           temp=temp->next;
        }while(temp!=head);
        cout<<endl;
    }
    
    void print_circular(){  //just to check if we made a circular linked list
        Node* temp=head;
        for(int i=1;i<=15;i++){
           cout<<temp->val<<"->";
           temp=temp->next;
        }
    }

    void insert_at_start(int val){  //o(n)
         Node* new_node=new Node(val);
         if(head==NULL){  //linked list is empty
            head=new_node;
            new_node->next=new_node;  //it is circular
            return;
         }
          
         Node* tail=head;
         while(tail->next!=head){
            tail=tail->next;
         }
         //now tail is pointing to the last node
         tail->next=new_node;
         new_node->next=head;
         head=new_node;
    }

    void insert_at_end(int val){  //o(n)
        Node* new_node=new Node( val);

        if(head==NULL){
            head=new_node;
            new_node->next=new_node;  //it is circular
            return;
        }
        Node* tail=head;
         while(tail->next!=head){
            tail=tail->next;
         }
         //now tail is pointing to the last node
         tail->next=new_node;
         new_node->next=head;
    }
    //insertion at kth position is similar to singular linked list

    void delete_at_start(){
        if(head==NULL){
            return;
        }
        Node* tail=head;
        Node* temp=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        head=head->next;
        tail->next=head;
        free(temp);
    }
    void delete_at_end(){
        if(head==NULL){
            return;
        }

        Node* tail=head;
        while(tail->next->next!=head){   
            tail=tail->next;
        }
        //here tail points to the last second node
        Node* to_be_del=tail->next; //the last node that is to be deleted.
        tail->next=head;
        free(to_be_del);
    }
    //deletion at kth position is similar to singular linked list

};
int main(){
    circular_linked_list cll;
    cll.insert_at_start(3);
    cll.insert_at_start(2);
    cll.insert_at_start(1);
    cll.display();
    // cll.print_circular();
    cll.insert_at_end(4);
    cll.insert_at_end(5);
    cll.display();
    cll.delete_at_start();
    cll.display();
    cll.delete_at_end();
    cll.display();
}
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

    void insertion_at_start(int val){
       Node* new_node=new Node(val);
       if(head==NULL){   //our linked list is empty.
        head=new_node;
        tail=new_node;
        return;
       }

       new_node->next=head;
       head->prev=new_node;
       head=new_node;
       return;
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

    void insert_at_k(int val,int k){  //assuming 1 based indexing
            Node* new_node=new Node(val);
           if(k==1){
            insertion_at_start(val);
           }
           int count=1;
           Node* temp=head;
           while(count<k-1){
             temp=temp->next;
           }
            
           //temp is now on (k-1)th position
           new_node->next=temp->next;
           temp->next=new_node;
           //abh hamare next vale pointer toh set hai.
           new_node->prev=temp;
           new_node->next->prev=new_node;

    }
    void delete_at_start(){
        if(head==NULL){  //no node present
            return;
        }
        Node* temp=head;
        head=head->next;
        if(head==NULL){  //if doubly linked list have only one node
            tail=NULL;
        }
        else{
            head->prev=NULL;
        }   
        free(temp);
    }
    void delete_at_end(){
        if(tail==NULL){  //no node present
            return;
        }
        Node* temp=tail;
        tail=tail->prev;
        if(tail==NULL){   //if doubly linked list have only one node
            head==NULL;
        }
        else{
          tail->next=NULL;
        }
        free(temp);
    }

    void delete_at_k(int k){  //assuming 1 based indexing
        Node* temp=head;
        int count=1;   
        if(k==1){
            delete_at_start();
            return;
        }
        while(count<k-1){
            temp=temp->next;
            count++;
        }
        Node* node_to_del=temp->next;
        //now temp is present on the node to be deleted
        temp->next=node_to_del->next;
        temp->next->prev=temp;
        free(node_to_del);
    }  
};
int main(){
    Node* new_node=new Node(5);
    Doubly_linked_list dl;
    dl.insertion_at_start(4);
    dl.insertion_at_start(3);
    dl.insertion_at_start(1);
    dl.display();
    dl.insert_at_end(5);
    dl.display();
    dl.insert_at_k(2,2);
    dl.display();
    dl.delete_at_start();
    dl.display();
    dl.delete_at_end();
    dl.display();
    int k;
    cin>>k; 
    dl.delete_at_k(k);
    dl.display();   
    return 0;
}
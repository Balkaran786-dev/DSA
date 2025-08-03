#include<iostream>
using namespace std;
class Node{
public:
   Node* next;
   int val;
   Node(int value){
    val=value;
    next=NULL;
   }
};
class queue{
     Node* head;
     Node* tail;
     int capacity;
     int curr_size;
     public:
     queue(int c){
        head=NULL;
        tail=NULL;
        capacity=c;
        curr_size=0;
     }
     bool Is_empty(){
        return head==NULL;
     }
     bool Is_full(){
        return curr_size==capacity;
     }
     int size(){
        return curr_size;
     }
     void enqueue(int data){   //insert at tail
        Node* new_node=new Node(data);
        if(head==NULL){
           head=new_node;
           tail=new_node; 
           return;
        }
        if(curr_size==capacity){
            cout<<"Overflow"<<endl;
            return;
        }
         tail->next=new_node;
         tail=new_node;
         curr_size++;
         return;
     }
     void dequeue(){  //deletion from head
        if(head==NULL){
            cout<<"Underflow\n";
            return;
        }
        Node* node_to_del=head;
        head=head->next;
        if(head==NULL){ //may be queue gets empty.
            tail==NULL;
        }
        free(node_to_del);
        curr_size--;
     }
     int front(){
        if(head==NULL){
            cout<<"Underflow\n";
            return INT16_MIN;
        }
        return head->val;
     }
     void display(){
        if(head==NULL){
            return;
        }
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
     }
     void show_pos(){
        if(head==NULL){
            cout<<"front:-" <<"NULL"<<endl;
            cout<<"Rear :-" <<"NULL"<<endl;
            return;
        }
        cout<<"front:-" <<head->val<<endl;
        cout<<"Rear :-" <<tail->val<<endl;
        return;
     }
};
int main(){
    queue qu(7);
    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(3);
    cout<<qu.front()<<endl;
    qu.dequeue();
    cout<<qu.front()<<endl;
    qu.enqueue(4);
    qu.enqueue(5);
    qu.display();
    qu.show_pos();
}
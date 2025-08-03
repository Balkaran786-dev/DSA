//Analogy
//front==head
//enqueue:- add at tail
//dequeue:- remove from head.

//advantage of this kind implementation: very space efficient.
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
       tail=NULL;
       head=NULL;
       curr_size=0;
       capacity=c;
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
        if(Is_full()){
         cout<<"Overflow"<<endl;
         return;
        }
        if(head==NULL){
           head=new_node;
           tail=new_node;
           curr_size++;
           return;
        }
        tail->next=new_node;
        tail=new_node;
        curr_size++;
        return;
     }
     void dequeue(){  //deletion from head
        if(head==NULL){
         cout<<"Underflow"<<endl;
         return;
        }
        Node* temp=head;
        head=head->next;
        if(head==NULL){
         tail=NULL;
        }
        free(temp);
        curr_size--;
        return;
     }
     int front(){
       if(head==NULL){
         cout<<"Underflow"<<endl;
         return INT16_MIN;
       }
       return head->val;
     }
     void display(){
        if(head==NULL){
         cout<<"NULL"<<endl;
          return;
        }
        Node* temp=head;
        while(temp!=NULL){
         cout<<temp->val<<"->";
         temp=temp->next;
        }cout<<"NULL\n";
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
    cout<<qu.Is_full()<<endl;
    cout<<qu.size()<<endl;
}
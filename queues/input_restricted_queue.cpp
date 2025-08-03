#include<bits/stdc++.h>
using namespace std;
class Node{
public:
   int val;
   Node* next;
   Node* prev;
   
   Node(int ele){
    val=ele;
    next=NULL;
    prev=NULL;
   }
};
class input_restricted_deque{
    Node* head;
    Node* tail;

    public:
    input_restricted_deque(){
        head=tail=NULL;
    }

    void push(int ele){
        Node* new_node=new Node(ele);
        if(head==NULL){
            head=tail=new_node;
            return;
        }
        tail->next=new_node;
        new_node->prev=tail;
        tail=tail->next;
        return;
    }

    void pop_front(){
        if(head==NULL){
            cout<<"Underflow"<<endl;
            return;
        }
        Node* node_to_del=head;
        head=head->next;
        if(head==NULL){
            tail=NULL;
            free(node_to_del);
            return;
        }
        head->prev=NULL;
        free(node_to_del);
        return;
    }

    void pop_back(){
        if(tail==NULL){
            cout<<"Underflow"<<endl;
            return;
        }
        Node* node_to_del=tail;
        tail=tail->prev;
        if(tail==NULL){
            head=NULL;
            free(node_to_del);
            return;
        }
        tail->next=NULL;
        free(node_to_del);
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
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    input_restricted_deque deq;
    deq.push(1);
    deq.push(2);
    deq.push(3);
    deq.push(4);
    deq.push(5);

    deq.display();

    deq.pop_front();
    deq.pop_back();

    deq.display();

    cout<<deq.front();
    return 0;
}
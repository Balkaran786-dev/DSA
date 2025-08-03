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

    void insert_at_start(int val){
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
        if(tail==NULL){  //empty
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
            insert_at_start(val);
            return;
           }
           int count=1;
           Node* temp=head;
           while(count<k-1){
             temp=temp->next;
             count++;
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
            head->prev=NULL; //if doubly linked list have more than one node
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
        while(count<k){
            temp=temp->next;
            count++;
        }
        //now temp is present on the node to be deleted
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }  
};
void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->prev<<" "<<temp->val<<" "<<temp->next<<endl;
        temp=temp->next;
    }
}
int main(){
    Doubly_linked_list dl;
    int n;
    cout<<"size of doubly linked_list is: "<<endl;
    cin>>n;
    int size=n;
    if(size!=0){
      cout<<"Give the values you want to insert in the doubly linked list:-"<<endl;
    }
    while(size--){
        int val;
        cin>>val;
        dl.insert_at_end(val);
    }
    int input1;
    cout<<"press 1 for insertion or press 2 for deletion:- "<<endl;
    cin>>input1;
    switch (input1){
    case 1:
        int value;
        cout<<"Enter the value you want to insert in the doubly linked list:- "<<endl;
        cin>>value;
        char input2;
        cout<<"press 's' for insertion in start or press 'r' for insertion at any random position or press 'l' to insert at the end of doubly linked list :-"<<endl;
        cin>>input2;
        cout<<"doubly linked list before insertion :-"<<endl;
        dl.display();
        switch (input2){
        case 's':
            dl.insert_at_start(value);
            cout<<"linked list after insertion :-"<<endl;
            dl.display();
            break;
        case 'r':
            int k;
            cout<<"Enter the position where you want to insert an element:- "<<endl;
            cin>>k;
            dl.insert_at_k(value,k);
            cout<<"linked list after insertion :-"<<endl;
            dl.display();
            break;
        case 'l':
            dl.insert_at_end(value);
            cout<<"linked list after insertion :-"<<endl;
            dl.display();
            break;
        default:
            cout<<"You have given a wrong input..."<<endl;
            break;
        }
        break;
    case 2:
        char input3;
        cout<<"press 's' to delete the node at the begining or press 'r' to delete a node present at a random position or press 'l' to delete the last node:- "<<endl;
        cin>>input3;
        cout<<"linked list before deletion :-"<<endl;
        dl.display();
        switch (input3)
        {
        case 's':
            dl.delete_at_start();
            cout<<"linked list after deletion :-"<<endl;
            dl.display();
            break;
        case 'r':
            int pos;
            cout<<"Enter the position where you want to apply deletion:- "<<endl;
            cin>>pos;
            dl.delete_at_k(pos);
            cout<<"linked list after deletion :-"<<endl;
            dl.display();
            break;
        case 'l':
            dl.delete_at_end();
            cout<<"linked list after deletion :-"<<endl;
            dl.display();
            break;
        default:
            cout<<"You have given a wrong input..."<<endl;
            break;
        }
        break;
    default:
        cout<<"You have given a wrong input..."<<endl;
        break;
    }
    
    display(dl.head);
    cout<<"\nName: Balkaran singh\nRollNo: 23103027\n"; 
    return 0; 

}
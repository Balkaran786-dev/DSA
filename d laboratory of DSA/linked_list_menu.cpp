#include<bits/stdc++.h>
using namespace std;
class Node{
 public:
    int data;
    Node* next;

    Node(int data){
       this->data=data;
       next=NULL;
    }
};
void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

    return;
}
void insert_at_start(Node *&head,int value){
    Node* new_node=new Node(value);
    if(head==NULL){
        head=new_node;
        return;
    }
    new_node->next=head;
    head=new_node;
    return;
}
void insert_at_end(Node* &head,int value){
    Node* new_node=new Node(value);
    if(head==NULL){
        insert_at_start(head,value);
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;

}
void insert_at_k(Node* &head,int value,int k){
    if(k==1){
        insert_at_start(head,value);
        return;
    }
    Node* temp=head;
    Node* new_node=new Node(value);
    int count=1;
    while(count<=k-2){
        temp=temp->next;
        count++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
    return;
}
void delete_at_start(Node* &head){
    if(head==NULL){
       cout<<"Linked list is already empty...."<<endl;
       return;
    }
    Node* temp=head;
    head=head->next;
    free(temp);
}
void delete_at_end(Node* &head){
    if(head==NULL){
       cout<<"Linked list is already empty...."<<endl;
       return;
    }
    else if(head->next==NULL){
        delete_at_start(head);
        return;
    }
    Node* temp1=head;
    while(temp1->next->next!=NULL){
        temp1=temp1->next;
    }
    Node* temp2=temp1->next;
    temp1->next=NULL;
    free(temp2);
}
void delete_at_k(Node* &head,int k){
    if(k==1){
        delete_at_start(head);
        return;
    }
    Node* temp1=head;
    int count=1;
    while(count<=k-2){
        temp1=temp1->next;
        count++;
    }
    Node* temp2=temp1->next;
    temp1->next=temp2->next;
    free(temp2);
}
int main(){
    Node* head=NULL;
    int n;
    cout<<"size of linked_list is: "<<endl;
    cin>>n;
    if(n!=0){
      cout<<"Give the values you want to insert in the linked list:-"<<endl;
    }
    while(n--){
        int val;
        cin>>val;
        insert_at_end(head,val);
    }
    int input1;
    cout<<"press 1 for insertion or press 2 for deletion:- "<<endl;
    cin>>input1;
    switch (input1){
    case 1:
        int value;
        cout<<"Enter the value you want to insert in the linked list:- "<<endl;
        cin>>value;
        char input2;
        cout<<"press 's' for insertion in start or press 'r' for insertion at any random position or press 'l' to insert at the end of linked list :-"<<endl;
        cin>>input2;
        cout<<"linked list before insertion :-"<<endl;
        display(head);
        switch (input2){
        case 's':
            insert_at_start(head,value);
            cout<<"linked list after insertion :-"<<endl;
            display(head);
            break;
        case 'r':
            int k;
            cout<<"Enter the position where you want to insert an element:- "<<endl;
            cin>>k;
            insert_at_k(head,value,k);
            cout<<"linked list after insertion :-"<<endl;
            display(head);
            break;
        case 'l':
            insert_at_end(head,value);
            cout<<"linked list after insertion :-"<<endl;
            display(head);
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
        display(head);
        switch (input3)
        {
        case 's':
            delete_at_start(head);
            cout<<"linked list after deletion :-"<<endl;
            display(head);
            break;
        case 'r':
            int pos;
            cout<<"Enter the position where you want to apply deletion:- "<<endl;
            cin>>pos;
            delete_at_k(head,pos);
            cout<<"linked list after deletion :-"<<endl;
            display(head);
            break;
        case 'l':
            delete_at_end(head);
            cout<<"linked list after deletion :-"<<endl;
            display(head);
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
    

    cout<<"\nName: Balkaran singh\nRollNo: 23103027\n";  
    return 0;
}
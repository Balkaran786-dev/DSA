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
    Node* tail;
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
    void insert_at_start(int val){  //o(1)
         Node* new_node=new Node(val);
         if(head==NULL){  //linked list is empty
            head=new_node;
            tail=new_node;
            new_node->next=new_node;  //it is circular
            return;
         }

         new_node->next=head;
         head=new_node;
         tail->next=head;
    }
    void insert_at_k(int value,int k,int size){
       if(k>size+1){
        cout<<"Wrong input"<<endl;
        return;
       }
       if(k==1){
        insert_at_start(value);
        return;
       }
       if(k==size+1){
        insert_at_end(value);
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
    void insert_at_end(int val){  //o(1)
        Node* new_node=new Node( val);

        if(head==NULL){
            head=new_node;
            tail=new_node;
            new_node->next=new_node;  //it is circular
            return;
        }
        
         tail->next=new_node;
         tail=new_node;
         new_node->next=head;
    }
    
    void delete_at_start(){
        if(head==NULL){
            return;
        }
        
        Node* temp=head;
        head=head->next;
        tail->next=head;
        free(temp);
    }
    void delete_at_k(int k,int size){
        
        if(k>size ){
           cout<<"Wrong input"<<endl;
           return;
        }
        if(k==1){
          delete_at_start();
          return;
        }
        if(k==size){
          delete_at_end();
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
    void delete_at_end(){
        if(head==NULL){
            return;
        }

        Node* temp=head;
        while(temp->next->next!=head){   
            temp=temp->next;
        }
        //here temp points to the last second node
        Node* to_be_del=temp->next; //the last node that is to be deleted.
        tail=temp;
        tail->next=head;
        free(to_be_del);
    }
    //deletion at kth position is similar to singular linked list
};
bool check_circular(Node* head){
    Node* temp=head->next;
    while(temp!=head && temp!=NULL){
        temp=temp->next;
    }
    if(temp==NULL) return false;
    else return true;
}
int main(){
    circular_linked_list cl;
     cl.head=NULL;
     cl.tail=NULL;
    int n;
    cout<<"size of circular linked_list is: "<<endl;
    cin>>n;
    int size=n;
    if(size!=0){
      cout<<"Give the values you want to insert in the linked list:-"<<endl;
    }
    while(size--){
        int val;
        cin>>val;
        cl.insert_at_end(val);
    }
    int input1;
    cout<<"press 1 for insertion or press 2 for deletion:- "<<endl;
    cin>>input1;
    switch (input1){
    case 1:
        int value;
        cout<<"Enter the value you want to insert in the circular linked list:- "<<endl;
        cin>>value;
        char input2;
        cout<<"press 's' for insertion in start or press 'r' for insertion at any random position or press 'l' to insert at the end of circular linked list :-"<<endl;
        cin>>input2;
        cout<<"circular linked list before insertion :-"<<endl;
        cl.display();
        switch (input2){
        case 's':
            cl.insert_at_start(value);
            cout<<"linked list after insertion :-"<<endl;
            cl.display();
            break;
        case 'r':
            int k;
            cout<<"Enter the position where you want to insert an element:- "<<endl;
            cin>>k;
            cl.insert_at_k(value,k,n);
            cout<<"linked list after insertion :-"<<endl;
            cl.display();
            break;
        case 'l':
            cl.insert_at_end(value);
            cout<<"linked list after insertion :-"<<endl;
            cl.display();
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
        cl.display();
        switch (input3)
        {
        case 's':
            cl.delete_at_start();
            cout<<"linked list after deletion :-"<<endl;
            cl.display();
            break;
        case 'r':
            int pos;
            cout<<"Enter the position where you want to apply deletion:- "<<endl;
            cin>>pos;
            cl.delete_at_k(pos,n);
            cout<<"linked list after deletion :-"<<endl;
            cl.display();
            break;
        case 'l':
            cl.delete_at_end();
            cout<<"linked list after deletion :-"<<endl;
            cl.display();
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
    cout<<(check_circular(cl.head)==1?"Yes it is a circular linked list":"No it is not a circular linked list");
    cout<<"\nName: Balkaran singh\nRollNo: 23103027\n"; 
    return 0;
}
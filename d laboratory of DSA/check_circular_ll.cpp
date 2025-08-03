#include<iostream>
using namespace std;
class Node{
public:
   Node* next;
   int val;

   Node(int val){
    next=NULL;
    this->val=val;
   }
};
class circular_linked_list{
    public:
    Node* head;
    Node* tail;
    circular_linked_list(){
        head=NULL;
        tail=NULL;
    }

    void display(){
        Node* temp=head;
        do{
           cout<<temp->val<<"->";
           temp=temp->next;
        }while(temp!=head);
        cout<<endl;
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

};
bool check_circular(Node* head){
    Node* temp=head->next;
    while(temp!=head && temp!=NULL){
        temp=temp->next;
    }
    if(temp==NULL) return false;
    else return true;
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
    circular_linked_list cl;
    cl.insert_at_end(1);
    cl.insert_at_end(2);
    cl.insert_at_end(3);
    cl.insert_at_end(4);
    cl.insert_at_end(5);
    cl.display();
    cout<<(check_circular(cl.head)==1? "yes it is a circular linked list":"No,it is not a circular linked")<<endl;
    cl.tail->next=NULL;
    display(cl.head);
    cout<<(check_circular(cl.head)==1? "yes it is a circular linked list":"No,it is not a circular linked")<<endl;
    return 0;
}

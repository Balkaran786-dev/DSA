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
class LinkedList{
public:
    Node* head;

    LinkedList(){
        head=NULL;
    }

    void insert(int val){
        Node* new_node=new Node(val);
        if(head==NULL){
            head=new_node;
            return;
        }
        Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

};

//assuming k to be less than or equal to size of linked list.
void delete_kth_node_from_end(Node* &head,int k){
    //forming two pointers
    Node* ptr1=head;
    Node* ptr2=head;

    //moving ptr2 from ptr1 at k steps
    int count=k;
    while(k--){
        ptr2=ptr2->next;
    }

    if(ptr2==NULL){  //if k is equal to size of linked list.
       Node* temp=head;
       head=head->next;
       free(temp);
       return;
    }


    //moving ptr2 and ptr1 till ptr2->next comes on NULL
    while(ptr2->next!=NULL){
        ptr2=ptr2->next;
        ptr1=ptr1->next;
    } 

    //now ptr1 is on previous node that is to be deleted
    Node* del=ptr1->next;
    ptr1->next=ptr1->next->next;
    free(del);
    return;
}
int main(){
    LinkedList ll;
    ll.insert(1);
    // ll.insert(2);
    // ll.insert(3);
    // ll.insert(4);
    // ll.insert(5);
    ll.display();
    delete_kth_node_from_end(ll.head,1);
    ll.display();
    return 0;
}

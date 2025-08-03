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
int length(Node* head){
    Node *temp=head;
    int len=0;
    while(temp->next!=NULL){
        len++;
        temp=temp->next;
    }
    temp->next=head;
    return len+1;
}
Node* rotate_byk_places(Node* &head,int k){
    Node* temp=head;
    int n=length(head); //calculating the length and pointing the last node to the head.
    
    //taking the temp to (n-k)th node
    k=k%n;    //if in case k is equal to or greater than size of linked list.
    int q=n-k-1;
    while(q--){
        temp=temp->next;
    }
    Node* new_head=temp->next;  //n-kth node ke aage vali node ko new head bna diya
    temp->next=NULL;    //n-kth node ko NULL point karva diya.
    return new_head;    
}  
int main(){
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.insert(6);
    ll.display();
    int k;
    cin>>k;
    ll.head=rotate_byk_places(ll.head,k);
    ll.display();
}
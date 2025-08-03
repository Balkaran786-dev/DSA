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

Node* reverseKLL(Node* head,int k){
    Node* prev=NULL;
    Node* curr=head;
    int curr_count=0;//for counting k times 

    while(curr!=NULL && curr_count<k){
       Node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        curr_count++;
    }

    //now,curr pointer points to k+1 node......
    if(curr!=NULL){  //it can be possible that our linked list gets complete
        Node* new_head=reverseKLL(curr,k);  //recursive call
        head->next=new_head;  //joing the previous k nodes to ahead k nodes...
    }

    return prev; 
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
    ll.head=reverseKLL(ll.head,k);
    ll.display();
    return 0;
}

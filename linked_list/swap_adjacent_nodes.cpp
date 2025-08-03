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
Node* swap_adj(Node* head){
    //base case
    if(head==NULL || head->next==NULL){  //first condition in case of even nodes and second in case of odd nodes
        return head;
    }
    
    Node* second_node=head->next;
    Node* new_head=swap_adj(second_node->next);
    head->next=new_head;
    second_node->next=head;
    
    return second_node;



    if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        int count=0;
        while(count<2){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            count++;
        }

        ListNode* new_head=swapPairs(curr);
        head->next=new_head;
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
    ll.head=swap_adj(ll.head);
    ll.display();
    return 0;
}
// #include<iostream>
// using namespace std;
// class Node{
// public:
//     int val;
//     Node* next;

//     Node(int value){
//         val=value;
//         next=NULL;
//     }
// };
// class LinkedList{
// public:
//     Node* head;

//     LinkedList(){
//         head=NULL;
//     }

//     void insert(int val){
//         Node* new_node=new Node(val);
//         if(head==NULL){
//             head=new_node;
//             return;
//         }
//         Node*temp=head;
//         while(temp->next!=NULL){
//             temp=temp->next;
//         }
//         temp->next=new_node;
//     }

//     void display(){
//         Node* temp = head;
//         while(temp!=NULL){
//             cout<<temp->val<<"->";
//             temp=temp->next;
//         }
//         cout<<"NULL"<<endl;
//     }

// };
// Node* reverseLL(Node* head){
//     Node* prev=NULL;
//     Node* curr=head;
//     Node* temp;
//     while(curr!=NULL){
//         temp=curr->next; //securing the location of next node
//         curr->next=prev; //attaching the current node to previous node 
//         prev=curr;       //we move the previous pointer to the place of current pointer.
//         curr=temp;       //we move the current pointer to the temp pointer location.
//     }

//     return prev;   //returning our prev pointer beacuse that is at the location of new head pointer.
// }
// int main(){
//     LinkedList ll;
//     ll.insert(1);
//     ll.insert(2);
//     ll.insert(3);
//     ll.insert(4);
//     ll.insert(5);
//     ll.display();
//     ll.head=reverseLL(ll.head);
//     ll.display();
//     return 0;
// }



//reversal of linked list through recursion;
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

Node* reverseLL(Node* curr,Node* prev){
    if(curr==NULL){       //prev at the previous node of curr node
        return prev;
    }               
    Node* temp=curr->next;
    curr->next=prev;
    return reverseLL(temp,curr);    
}
int main(){
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.display();
    ll.head=reverseLL(ll.head,NULL);
    ll.display();
    return 0;
}

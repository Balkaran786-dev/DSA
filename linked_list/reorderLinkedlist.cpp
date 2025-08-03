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
void reorder_LinkedList(Node* &head){
       //can check if a given linked list has at least 3 nodes.

       //finding middle node
       Node* slow=head;
       Node* fast=head;
       while(fast && fast->next){
          slow=slow->next;
          fast=fast->next->next;
       }
       
       //now slow is pointing to the middle node;
       //now,reverse the second half of the linked list
       Node* curr=slow->next;
       Node* prev=slow;
       slow->next=NULL;
       Node* temp1;
       while(curr){
          temp1=curr->next;
          curr->next=prev;
          prev=curr;
          curr=temp1;
       }

       Node* h1=head;
       Node* h2=prev;
       Node* temp2;
       while(h1!=h2){
          temp2=h1->next;
          h1->next=h2;
          h1=h2;
          h2=temp2;
       }

}
int main(){
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.insert(6);
    ll.insert(7);
    ll.display();
    reorder_LinkedList(ll.head);
    ll.display();
    return 0;
}



// //2nd approach very similar to 1st one..

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
// void reorder_LinkedList(Node* &head){
//        //finding middle node
//        Node* slow=head;
//        Node* fast=head;
//        while(fast->next && fast->next->next){
//           slow=slow->next;
//           fast=fast->next->next;
//        }
       
//        //now slow is pointing to the node previous to middle node;
//        //now,reverse the second half of the linked list
       
       
//        Node* prev=slow->next;
//        slow->next=NULL;
//        slow=prev;
//        Node* curr=slow->next;
//        slow->next=NULL;
//        Node* temp;
//        while(curr){
//           temp=curr->next;
//           curr->next=prev;
//           prev=curr;
//           curr=temp;
//        }

//        Node* h1=head;
//        Node* h2=prev;
//        Node* ahead1;
//        Node* ahead2;
//        while(h1 && h2){
//           ahead1=h1->next;
//           ahead2=h2->next;
//           h1->next=h2;
//           h2->next=ahead1;
//           h1=ahead1;
//           h2=ahead2;
//        }

// }
// int main(){
//     LinkedList ll;
//     ll.insert(1);
//     ll.insert(2);
//     ll.insert(3);
//     ll.insert(4);
//     ll.insert(5);
//     ll.insert(6);
//     ll.insert(7);
//     ll.display();
//     reorder_LinkedList(ll.head);
//     ll.display();
//     return 0;
// }



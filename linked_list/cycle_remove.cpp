// #include<iostream>  //slow fast pointer..
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
// Node* cycle_detect(Node* &head){
//     Node* slow=head;
//     Node* fast=head;

//     while(fast!=NULL && fast->next!=NULL){
//         slow=slow->next;
//         fast=fast->next->next;
//         if(slow==fast){
//             return slow;
//         }
//     }
//     return NULL;   //agar uuper vala loop break hogaya matlab,
//                   //there exist some NULL,hence there would be no cycle present in the ll.
// }
// void cycle_removal(Node* &head){
//     Node* fast=head;
//     Node* slow=cycle_detect(head);
//     if(slow==NULL){
//         return;
//     }
    
//     while(fast->next!=slow->next){
//         slow=slow->next;
//         fast=fast->next; 
//     }
//     slow->next=NULL;
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
//     ll.insert(8);
//     ll.head->next->next->next->next->next->next->next->next=ll.head->next;
//     cycle_removal(ll.head);
//     ll.display();
// }


#include<iostream>  //slow fast pointer..
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
bool cycle_detect(Node* &head){
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            cout<<slow->val<<endl;
            return true;
        }
    }
    return false;   //agar uuper vala loop break hogaya matlab,
                  //there exist some NULL,hence there would be no cycle present in the ll.
}
void cycle_removal(Node* &head){
    Node* fast=head;
    Node* slow=head;
    
    do{                   //if we used while loop with this same condition,then
                          //it wouldn't enter the loop,because initially bith the pointers are
                          //pointing to head.
       slow=slow->next;
       fast=fast->next->next;
    } while(slow!=fast);

    fast=head;
    while(slow->next!=fast->next){
       slow=slow->next;
       fast=fast->next;
    }
    slow->next=NULL;
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
    ll.insert(8);
    ll.head->next->next->next->next->next->next->next->next=ll.head->next;
    cout<<cycle_detect(ll.head)<<endl;
    cout<<"After removing the cycle,we got this linked list:";
    cycle_removal(ll.head);
    ll.display();
}
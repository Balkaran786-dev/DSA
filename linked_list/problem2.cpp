// //by taking two pointer variable
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

// void deletion(Node *prev){
//     Node* temp=prev->next;
//     prev->next=prev->next->next;
//     free(temp);
// }

// void delete_duplicates(Node* &head){
//     Node* prev=head;
//     Node* curr=head->next;
//     while(curr!=NULL){
//         if(prev->val==curr->val){
//             curr=curr->next;
//             deletion(prev);
//         }
//         else{
//             prev=prev->next;
//             curr=curr->next;
//         }
//     }
// }

// int main(){
//     LinkedList ll;
//     ll.insert(1);
//     ll.insert(2);
//     ll.insert(2);
//     ll.insert(3);
//     ll.insert(3);
//     ll.insert(4);
//     ll.insert(4);
//     ll.insert(4);
//     ll.display();
//     delete_duplicates(ll.head);
//     ll.display();
//     return 0;
// }

// //by taking only one pointer variable
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

// void deletion(Node *curr){
//     Node* temp=curr->next;
//     curr->next=curr->next->next;
//     free(temp);
// }

// void delete_duplicates(Node* &head){
//     Node* curr=head;
//     while(curr->next!=NULL){
//         if(curr->val==curr->next->val){
//             deletion(curr);
//         }
//         else{
//             curr=curr->next;
//         }
//     }
// }

// int main(){
//     LinkedList ll;
//     ll.insert(1);
//     ll.insert(2);
//     ll.insert(2);
//     ll.insert(3);
//     ll.insert(3);
//     ll.insert(4);
//     ll.insert(4);
//     ll.insert(4);
//     ll.display();
//     delete_duplicates(ll.head);
//     ll.display();
//     return 0;
// }


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

void delete_duplicates(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        Node* curr = temp->next;
        while(curr!=NULL && curr->val==temp->val){
            curr=curr->next;
        }
        temp->next=curr;
        temp=curr;
    }
}
int main(){
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(2);
    ll.insert(3);
    ll.insert(3);
    ll.insert(4);
    ll.insert(4);
    ll.insert(5);
    ll.insert(6);
    ll.display();
    delete_duplicates(ll.head);
    ll.display();
    return 0;
}
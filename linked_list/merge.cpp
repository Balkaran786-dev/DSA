// #include<iostream>  //by creting a new merged linked list.
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

// Node* merge(Node* head1,Node* head2,LinkedList merge){
//     Node* ptr1=head1;
//     Node* ptr2=head2;

//     while(ptr1!=NULL && ptr2!=NULL){
//         if(ptr1->val>ptr2->val){
//             merge.insert(ptr2->val);
//             ptr2=ptr2->next;
//         }
//         else if(ptr1->val<ptr2->val){
//             merge.insert(ptr1->val);
//             ptr1=ptr1->next;
//         }
//         else{
//             merge.insert(ptr1->val);
//             merge.insert(ptr2->val);
//             ptr1=ptr1->next;
//             ptr2=ptr2->next;
//         }
//     }
//     while(ptr1!=NULL){
//         merge.insert(ptr1->val);
//         ptr1=ptr1->next;
//     }
//     while(ptr2!=NULL){
//         merge.insert(ptr2->val);
//         ptr2=ptr2->next;
//     }
//     return merge.head;
// }
// int main(){
//     LinkedList l1;
//     l1.insert(1);
//     l1.insert(5);
//     l1.insert(7);
//     LinkedList l2;
//     l2.insert(1);
//     l2.insert(6);
//     l2.insert(8);
//     LinkedList l3;
//     l3.head=merge(l1.head,l2.head,l3);
//     l3.display();
//     return 0;
// }


//by not creating a new linked list
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

Node* merge(Node* head1,Node* head2){
    //creting a dummynode 
   Node* dummyhead=new Node(-1);

   //creating ptr1, ptr2, ptr3
   Node* ptr1=head1;
   Node* ptr2=head2;
   Node* ptr3=dummyhead;

   //comparing values and joining it with ptr3
    while(ptr1 && ptr2){
    if(ptr1->val>ptr2->val){
        ptr3->next=ptr2;
        ptr2=ptr2->next;
    } 
    else if(ptr1->val<ptr2->val){
        ptr3->next=ptr1;
        ptr1=ptr1->next;
    }
    else{
        ptr3->next=ptr2;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
        ptr3=ptr3->next;  //ptr3 ko aage nbhi move krna hai
    }

    if(ptr1){
      ptr3->next=ptr1;
    }
    else{
      ptr3->next=ptr2;
    }

   return dummyhead->next;  //this is the pointing to the start of merged linked list 
}
int main(){
    LinkedList l1;
    l1.insert(1);
    l1.insert(7);
    l1.insert(9);
    LinkedList l2;
    l2.insert(4);

    LinkedList l3;
    l3.head=merge(l1.head,l2.head);
    l3.display();
    return 0;
}
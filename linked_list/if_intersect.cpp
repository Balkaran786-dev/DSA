// #include<iostream>  //o(n*m) complexity where n and m are the lengths of the linked lists.
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
// Node* if_intersect(Node* head1,Node* head2){
//     Node* ptr1=head1;
//     while(ptr1!=NULL){
//         Node* ptr2=head2;
//         while(ptr2!=NULL){
//             if(ptr1==ptr2){
//                 return ptr1;
//             }
//             else{
//                 ptr2=ptr2->next;
//             }
//         }
//         ptr1=ptr1->next;
//     }
//     return NULL;
// }
// int main(){

//     LinkedList LL1;
//     LL1.insert(1);
//     LL1.insert(2);
//     LL1.insert(3);
//     LL1.insert(4);
//     LL1.insert(5);

//     LinkedList LL2;
//     LL2.insert(5);
//     LL2.insert(7);
//     LL2.head->next->next=LL1.head->next->next->next; //intersecting two ll

//     Node* intersection=if_intersect(LL1.head,LL2.head);
//     if(intersection){
//         cout<<intersection->val<<endl;
//     }
//     else{
//         cout<<"-1"<<endl;
//     }
//     return 0;
// }


// #include<iostream> // o(n+m)
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
// int get_length(Node*head){
//     Node*temp=head;
//     int length=0;
//     while(temp!=NULL){
//         length++;
//         temp=temp->next;
//     }
//     return length;
// }
// Node* move_linkedlist_by_k(Node*head,int k){
          
//       while(k--){
//         head=head->next;
//       }

//       return head;
// }
// Node* if_intersect(Node*head1,Node*head2){
//     //calculating the lengths of both the linkedlists
//     int l1=get_length(head1);
//     int l2=get_length(head2);

//     Node* ptr1,*ptr2;
//     //calculating the difference the lengths
//     if(l1>l2){  //first linkedlist is bigger
//         int k=l1-l2;
//          ptr1=move_linkedlist_by_k(head1,k);
//          ptr2=head2;
//     }
//     else{  //second linkedlist is bigger
//         int k=l2-l1;
//          ptr2=move_linkedlist_by_k(head2,k);
//          ptr1=head1;
//     }

//     //comparing the pointer variables.
//     while(ptr1!=NULL && ptr2!=NULL){
//         if(ptr1==ptr2){
//             return ptr1;
//         }
//         else{
//             ptr1=ptr1->next;
//             ptr2=ptr2->next;
//         }
//     }
//     return NULL;
// }
// int main(){

//     LinkedList LL1;
//     LL1.insert(1);
//     LL1.insert(2);
//     LL1.insert(3);
//     LL1.insert(9);
//     LL1.insert(5);
//     //1->2->3->9->5->NULL

//     LinkedList LL2;
//     LL2.insert(8);
//     LL2.insert(7);
//     //8->7->9->->5->NULL
//     LL2.head->next->next=LL1.head->next->next->next; //intersecting two ll
    
//     Node* intersection=if_intersect(LL1.head,LL2.head);
//     if(intersection){
//         cout<<intersection->val<<endl;
//     }
//     else{
//         cout<<"-1"<<endl;
//     }
//     return 0;
// }




// //by the making changes in the definition of class Node.
// #include<iostream>  o(n+m)
// using namespace std;
// class Node{
// public:
//     int val;
//     Node* next;
//     bool is_visted;

//     Node(int value){
//         val=value;
//         next=NULL;
//         is_visted=false;
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
// Node* if_intersect(Node* head1,Node* head2){
//     Node*ptr1=head1;
//     Node*ptr2=head2;

//     while(ptr1!=NULL){
//         ptr1->is_visted=true;
//         ptr1=ptr1->next;
//     }

//     while(ptr2!=NULL){
//         if(ptr2->is_visted==true){
//             return ptr2;
//         }
//         else{
//             ptr2=ptr2->next;
//         }
//     }
//     return NULL;

// }
// int main(){

    // LinkedList LL1;
    // LL1.insert(1);
    // LL1.insert(2);
    // LL1.insert(3);
    // LL1.insert(9);
    // LL1.insert(5);
    // //1->2->3->9->5->NULL

    // LinkedList LL2;
    // LL2.insert(8);
    // LL2.insert(7);
    // //8->7->9->->5->NULL
    // LL2.head->next->next=LL1.head->next->next->next; //intersecting two ll
    
//     Node* intersection=if_intersect(LL1.head,LL2.head);
//     if(intersection){
//         cout<<intersection->val<<endl;
//     }
//     else{
//         cout<<"-1"<<endl;
//     }
//     return 0;
// }


//using stacks
#include<iostream> // o(n+m)
#include<stack>
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
void if_intersect(Node* head1,Node* head2){
     stack<Node*> st1;
     stack<Node*> st2;
     Node* curr1=head1;
     while(curr1!=NULL){
        st1.push(curr1);
        curr1=curr1->next;
     }
     Node* curr2=head2;
     while(curr2!=NULL){
        st2.push(curr2);
        curr2=curr2->next;
     }
     
     Node* intersection=NULL;
     while(st1.top()==st2.top()){
        intersection=st1.top();
        st1.pop();
        st2.pop();
     }
     
     if(intersection==NULL){
        cout<<"No intersection";
     }
     else{
        cout<<intersection->val;
     }
}
int main(){
    
    LinkedList LL1;
    LL1.insert(1);
    LL1.insert(2);
    LL1.insert(3);
    LL1.insert(9);
    LL1.insert(5);
    //1->2->3->9->5->NULL

    LinkedList LL2;
    LL2.insert(8);
    LL2.insert(7);
    //8->7->9->->5->NULL
    LL2.head->next->next=LL1.head->next->next->next; //intersecting two ll
    if_intersect(LL1.head,LL2.head);
    return 0;
}
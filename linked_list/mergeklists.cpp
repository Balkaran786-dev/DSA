#include<iostream>
#include<vector>
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
        Node* temp=head;
        while(temp->next!=NULL){
             temp=temp->next;
        }
        temp->next=new_node;
    }

    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
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

Node* mergek_lists(vector<Node* > &lists){
    if(lists.size()==0){
        return NULL;
    }

    while(lists.size()>1){
        Node* merged_head=merge(lists[0],lists[1]);
        lists.push_back(merged_head);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }

    return lists[0];
}
int main(){
    LinkedList l1;
    l1.insert(1);
    l1.insert(5);
    l1.insert(7);

    LinkedList l2;
    l2.insert(2);
    l2.insert(4);
    l2.insert(8);

    LinkedList l3;
    l3.insert(3);
    l3.insert(6);
    
    vector<Node* > lists;
    lists.push_back(l1.head);
    lists.push_back(l2.head);
    lists.push_back(l3.head);

    LinkedList merged_list;
    merged_list.head=mergek_lists(lists);
    merged_list.display();
    return 0;
}
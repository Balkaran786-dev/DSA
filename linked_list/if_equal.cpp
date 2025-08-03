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
string if_equal(Node* head1,Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->val!=temp2->val){
            return "Not equal";
        }
        else{
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    
    if(temp1==NULL && temp2==NULL){
        return "Equal";
    }                                 //in place of this if else,
                                     // you can write->  return(temp1==NULL && temp2==NULL)
    else{
        return "Not Equal";
    }
    
}
int main(){
    LinkedList LL1;
    LL1.insert(1);
    LL1.insert(2);
    LL1.insert(3);
    LL1.insert(4);
    LL1.insert(5);
    LL1.insert(6);
    LinkedList LL2;
    LL2.insert(1);
    LL2.insert(2);
    LL2.insert(3);
    LL2.insert(4);
    LL2.insert(5);
  
    cout<<if_equal(LL1.head,LL2.head);

    return 0;
}
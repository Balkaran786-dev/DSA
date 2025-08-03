#include<iostream>
using namespace std;
class Node{
public:
    Node* next;
    int val;

    Node(int data){
        this->val=data;
        next=NULL;
    }
};
class stack{
 public:
    Node* head;
    int curr_size;
    int capacity;

    stack(int c){
        this->head=NULL;
        curr_size=0;
        capacity=c;
    }

    bool Is_empty(){
        return head==NULL;
    }

    bool Is_full(){
        return curr_size==capacity;
    }

    void push(int value){
        Node* new_node=new Node(value);
        if(head==NULL){
            curr_size++;
            head=new_node;
            return;
        }
        if(Is_full()){
            cout<<"Overflow condition mets"<<endl;
            return;
        }
        new_node->next=head;
        head=new_node;
        curr_size++;
        return;
    }

    void pop(){
        if(Is_empty()){
            cout<<"underflow condition mets"<<endl;
            return;
        }
        Node* to_be_del=head;
        head=head->next;
        curr_size--;
        free(to_be_del);
        return;
    }
    void display(){
        if(Is_empty()){
            cout<<"Empty"<<endl;
            return;
        }
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<endl;
            temp=temp->next;
        }
    }
};
int main(){
    int n;
    cout<<"Give the size of stack: ";
    cin>>n;
    stack st(n);
    while(true){
     int input1;
     cout<<"press 1 to push or press 2 to pop:- "<<endl;
     cin>>input1;
     switch (input1){
     case 1:
        int value;
        cout<<"Enter the value you want to push in the stack:- "<<endl;
        cin>>value;
        st.push(value);
        cout<<"display of my stack: "<<endl;
        st.display();
        break;
     case 2:
        st.pop();
        cout<<"display of my stack: "<<endl;
        st.display();
        break;
     default:
        cout<<"You have given a wrong input..."<<endl;
        break;
    }
     string reply;
     cout<<"Do you want to continue the proccess?";
     cin>>reply;
     if(reply!="yes"){
        break;
     }
    }
    return 0;
}
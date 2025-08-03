#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* next;

    Node(int data){
        val=data;
        next=NULL;
    }
};
void insert_at_end(Node* &head,int val){
    Node* new_node=new Node(val);
    Node* temp=head;
    if(head==NULL){
        head=new_node;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}


void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
} 
int main(){
    Node* head=new Node(1);
    Node* p=head;
    insert_at_end(head,2);
    insert_at_end(head,3);
    insert_at_end(head,4);
    insert_at_end(head,5);
    insert_at_end(head,6);
    insert_at_end(head,7);
    insert_at_end(head,8);
    insert_at_end(head,9);
    insert_at_end(head,10);

    display(head);

    int n,k;
    cin>>n>>k;

    int extra=n%k;
    int ele=n/k;

    vector<Node*> ans;

    int i=1;   
    Node* headp=head;
    while(i<=extra){  //itne mein mere ele+1 ayenge
       Node* head1=NULL;
       int nodes=0;
       while(nodes!=ele+1 && headp!=NULL){
        insert_at_end(head1,headp->val);
        headp=headp->next;
        nodes++;
       }
       ans.push_back(head1);
       i++;
    }
    
    int j=1;
    while(j<=k-extra){
       Node* head1=NULL;
       int nodes=0;
       while(nodes!=ele && headp!=NULL){
        insert_at_end(head1,headp->val);
        headp=headp->next;
        nodes++;
       }
       ans.push_back(head1);
       j++;
    }
    for(auto ele:ans){
        display(ele);
    }
    return 0;
}
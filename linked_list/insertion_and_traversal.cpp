 #include<iostream>
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
void insertathead(Node* &head,int val){
    Node *new_node=new Node(val);
    new_node->next=head;
    head=new_node;
}

void insert_at_end(Node* &head,int val){

    Node* new_node=new Node(val);
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    //temp has arrived last node.
    temp->next=new_node;
    //no need to make new_node->next=NULL.
    //as we have defined any node with a predefined next=NULL.
}

void insert_at_position(Node* head,int val,int pos){
    if(pos==0) insertathead(head,val);

    Node* new_node=new Node(val);
    Node* temp= head;
    int current_pos=0;
    while(current_pos!=pos-1){
        temp=temp->next;
        current_pos++;
    }
    //temp has reached pos-1
    new_node->next=temp->next; //new node ko pos vali node pe point kardiya
    temp->next=new_node;      //pos-1 vali node ko new node pe point kardiya
}

void update(Node* head,int val,int pos){
    Node* temp=head;
    int current_pos=0;
    while(current_pos!=pos){
        temp=temp->next;
        current_pos++;
    }
    //temp has reached pos.
    temp->val=val;
   
}

void delete_at_start(Node* &head){
    Node* temp=head;//node to be deleted.
    head=head->next;
    free(temp);  //this basically takes a pointer as an arguement and free up the space occupied by that pointer.
}

void delete_at_end(Node* head){
    Node* second_last=head;
    while(second_last->next->next!=NULL){
        second_last=second_last->next;
    }
    Node*temp=second_last->next;
    second_last->next=NULL;
    free(temp);
}

void delete_at_position(Node* head,int pos){
    if(pos==0) delete_at_start(head);
    Node* prev=head;
    int current_pos=0;
    while(current_pos!=pos-1){
        prev=prev->next;
        current_pos++;
    }
    Node* temp=prev->next;
    prev->next=prev->next->next;
    free(temp);
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
    Node* head=NULL;
   
    insertathead(head,2);
    display(head);
    insertathead(head,1);
    display(head);
    insert_at_end(head,3);
    display(head);
    insert_at_position(head,4,1);
    display(head);
    update(head,5,2);
    display(head); 
    // delete_at_start(head);
    // display(head);
    // delete_at_end(head);
    // display(head);
    // insertathead(head,3);
    // insertathead(head,2);
    // insertathead(head,1);
    // delete_at_position(head,3);
    // display(head);
    return 0;
}
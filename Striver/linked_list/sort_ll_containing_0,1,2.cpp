//brute force o(n)-time traversing two time
//take variable cnt0,cnt1,cnt2
//first time traverse and cnt these.
//second time put values in it.



//optimal  time-o(n) traversing only single time
Node* sortList(Node *head){
    // Write your code here.
    if(!head || !head->next) return head;

    Node* zerohead=new Node(-1);
    Node* onehead=new Node(-1);
    Node* twohead=new Node(-1);
    Node* zero=zerohead;
    Node* one=onehead;
    Node* two=twohead;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zero->next=temp;
            zero=temp;
        }
        else if(temp->data==1){
            one->next=temp;
            one=temp;
        }
        else{
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
    }

    zero->next=(onehead->next?onehead->next:twohead->next);
    one->next=twohead->next;
    two->next=NULL;
    return zerohead->next;
}
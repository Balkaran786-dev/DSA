//same logic can be applied in singly ll..
Node * removeDuplicates(Node *head)
{
    // Write your code here
    
        
        Node* temp=head;
        while(temp && temp->next){
            Node* next_Node=temp->next;
            while(next_Node!=NULL && next_Node->data==temp->data){
               Node* duplicate=next_Node;
               next_Node=next_Node->next;
               delete(duplicate);
            }
            temp->next=next_Node;
            if(next_Node!=NULL) next_Node->prev=temp;
            temp=temp->next;
        }
        return head;
}
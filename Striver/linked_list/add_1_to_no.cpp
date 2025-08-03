//1st solution:-
// revrse the ll , add 1 and then reverse again.


//2nd solution, only recursion can help you to move backward.
class Solution {
  public:
    Node* add_1_helper(Node* curr,int &carry){
        if(curr==NULL) return NULL;
        
        Node* new_node=add_1_helper(curr->next,carry);
        
        int val=curr->data+carry;
        int remain=val%10;
        carry=val/10;
        curr->data=remain;
        curr->next=new_node;
        return curr;
    }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        int carry=1;
        Node* ans=add_1_helper(head,carry);
        if(carry==1){
            Node* new_Node=new Node(1);
            new_Node->next=ans;
            ans=new_Node;
        }
        return ans;
    }
};


//
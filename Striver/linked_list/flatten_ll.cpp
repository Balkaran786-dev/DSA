//very similar to merge k lists..only difference here, we need to merge the linked list one by one that are moving downward
//here we took help of recursion

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* merge_helper(Node* l1,Node* l2){
        Node* dummy_Node=new Node(-1);
        Node* temp=dummy_Node;
        while(l1 && l2){
            if(l1->data<l2->data){
                temp->bottom=l1;
                temp=l1;
                l1=l1->bottom;
            }
            else{
                temp->bottom=l2;
                temp=l2;
                l2=l2->bottom;
            }
        }
        
        if(l1) temp->bottom=l1;
        else temp->bottom=l2;
        
        return dummy_Node->bottom;
    }
    Node* flatten_helper(Node* curr){
        if(!curr) return NULL;
        
        Node* right=flatten_helper(curr->next);
        Node* merged=merge_helper(curr,right);
        return merged;
    }
    Node *flatten(Node *root) {
        // Your code here
        return flatten_helper(root);
    }
};



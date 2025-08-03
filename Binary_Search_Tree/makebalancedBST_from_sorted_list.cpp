class Solution {
public:
    ListNode* middle_ele(ListNode* curr,ListNode* &last){
        ListNode* fast=curr;
        ListNode* slow=curr;
        while(fast!=NULL && fast->next!=NULL){
            if(slow!=curr){ //so that last remain on one lesser node of slow
                last=last->next;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    TreeNode* get_tree(ListNode* head){
        if(head==NULL) return NULL;   //when only two nodes,mid will be be second,so when we call for right subtree by mid+1 , that will be NULL,so to handle that case.
        if(head->next==NULL){       //when only one node is present directly form its treenode and retturn it
           TreeNode* root=new TreeNode(head->val);
           return root;            
        }
        
        ListNode* last=head;  //to track the node before middle one,then i will make it point to NULL;
        //so that when i pass head in left subtree,it will check only the left part of the linked list.
    
        ListNode* mid=middle_ele(head,last);
        last->next=NULL;
        TreeNode* root=new TreeNode(mid->val);
        root->left=get_tree(head);
        root->right=get_tree(mid->next);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        return get_tree(head);
    }
};
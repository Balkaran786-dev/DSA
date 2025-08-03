class Solution {    /// recursion tree se kro yrr calculate time , o((n+n/2)logn) time  and o(logn) space {internal stack}
public:

    ListNode* find_middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* list1,ListNode* list2){
        ListNode* dummyNode=new ListNode(-1);
        ListNode* temp=dummyNode;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        if(list1) temp->next=list1;
        else temp->next=list2;

        return dummyNode->next;
    }

    ListNode* sort_ll(ListNode* &head){
        if(!head || !head->next) return head;

        ListNode* middle=find_middle(head);
        ListNode* right=middle->next;
        middle->next=NULL;
        ListNode* left=head;
        left=sort_ll(left);
        right=sort_ll(right);
        return merge(left,right);
    }

    ListNode* sortList(ListNode* head) {
        return sort_ll(head);
    }
};
//bruteforce acc to me.. form a separate linkedlist and insert to it.



//here im not forming a new linked,
// im storing my sum in the 1st linked, if it is shorter, ill attach it with the second one.
// to just attach , i have take temp. also temp will help to attach to the extra node formed at the end due ti an extra carry.

class Solution {
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* temp=NULL;  //this will be on the prev node while calculation would help at last, when first number is smaller than second.
        int val1,val2,sum,remain,carry=0;
    
        while(temp1!=NULL && temp2!=NULL){
             val1=temp1->val;
             val2=temp2->val;
             sum=val1+val2+carry;

             remain=sum%10;
             carry=sum/10;
             temp1->val=remain;

             temp=temp1;
             temp1=temp1->next;
             temp2=temp2->next;
             
        }
        while(temp1!=NULL){
            val1=temp1->val;
            sum=val1+carry;
            remain=sum%10;
            carry=sum/10;
            temp1->val=remain;

            temp=temp1;
            temp1=temp1->next;
        }
        if(temp2!=NULL){
            temp->next=temp2;
        }
        while(temp2!=NULL){
           
            val2=temp2->val;
            sum=val2+carry;
            remain=sum%10;
            carry=sum/10;
            temp2->val=remain;

            temp=temp2;
            temp2=temp2->next;
        }

        if(carry!=0){
            ListNode* extra=new ListNode(1);
            temp->next=extra;
        }
       return l1;
    }
};
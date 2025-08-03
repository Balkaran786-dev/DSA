// first approach is reverse both the numbers.
// and then while calculating, don't need to make a new linked list.
// place you ans in the first one and keep reversing it side by side and even if it would 
// turned out to be smaller than the second one,we will attach the last node of first one with
// second ll, and then start placing our ans in it.





//second approach using stack..
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1,st2;

        while(l1!=NULL){
            st1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL){
            st2.push(l2->val);
            l2=l2->next;
        }
  
        ListNode* ans=NULL;
        int sum=0;
        int carry=0;
        int remain=0;
        while(!st1.empty() || !st2.empty()){
              sum+=carry;
              if(!st1.empty()){
                sum+=st1.top();
                st1.pop();
              }
              if(!st2.empty()){
                sum+=st2.top();
                st2.pop();
              }
              remain=sum%10;
              carry=sum/10;
              ListNode* new_node=new ListNode(remain);
              new_node->next=ans;
              ans=new_node;
              sum=0;
        } 
        if(carry!=0){
            ListNode* new_node=new ListNode(1);
            new_node->next=ans;
            ans=new_node;
        }
        return ans;
    }
};





//3rd approach
//using internal stack.

//for that , you need to calculate the len of both ll.
//move the head of larger ll that many times so that both heads are at same level,
// now call the recursive function and while backtracking , place your ans in the larger ll,
// after function, while carry!=0, app add krte rho apne node mein and if require last mein ek 1 node aur add krni hogi,
// that we can handle...


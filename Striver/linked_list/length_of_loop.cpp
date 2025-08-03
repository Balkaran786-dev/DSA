
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    bool hasCycle(Node *head,Node* &start) {
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                start=slow;
                return true;
            }
        }
        return false;
    }
    int countNodesinLoop(Node *head) {
        Node* start=NULL;
        bool if_loop=hasCycle(head,start);
        if(!if_loop) return 0;
        
        Node* p=start->next;
        int cnt=1;
        while(p!=start){
            cnt++;
            p=p->next;
        }
        return cnt;
    }
};


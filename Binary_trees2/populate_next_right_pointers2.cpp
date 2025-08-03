//o(n) time and o(n) space solution you know.



//o(1) space 
class Solution {
public:
    Node* connect(Node* root) {
         Node* head=root;
         while(head!=NULL){
             Node* dummy_node=new Node(0);
             Node* temp=dummy_node;
             while(head!=NULL){
                if(head->left){
                     temp->next=head->left;
                     temp=temp->next;
                }
                if(head->right){
                     temp->next=head->right;
                     temp=temp->next;
                }
                head=head->next;
             }
             head=dummy_node->next;
         }
         return root;
    }
};
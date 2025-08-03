class Solution{
public:
    void merge(Node* root1,Node* root2,vector<Node*> &lists){
             Node* dummy_node=new Node(-1);
             while(root1!=NULL && root2!=NULL){
                if(root1->val==root2->val){
                     dummy_node->next=root1;
                     root1=root1->next;
                     dummy_node->next=root2;
                     root2=root2->next;
                }
                else if(root1->val<root2->val){
                    dummy_node->next=root1;
                    root1=root1->next;
                }
                else{
                    dummy_node->next=root2;
                    root2=root2->next;
                }
             }

             while(!root1){
                dummy_node->next=root1;
                root1=root1->next;
             }
             while(!root2){
                dummy_node->next=root2;
                root2=root2->next;
             }
             lists.push_back(dummy_node->next);
    }
    Node* mergekll(vector<Node*> lists){
        if(lists.size()==0){
            return NULL;
        }

        while(lists.size()!=1){
            Node* head1=lists.back();
            lists.pop_back();
            Node* head2=lists.back();
            lists.pop_back();
            merge(head1,head2,lists);
        }

        return lists[0];
    }
};
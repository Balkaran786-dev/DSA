

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int,int>> vec;
        if(!head->next) return vec;
        Node* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        
        while(head!=tail && head->prev!=tail){
            int val=head->data+tail->data;
            if(val==target){
                vec.push_back({head->data,tail->data});
                head=head->next;
                tail=tail->prev;
            }
            else if(val>target){
                tail=tail->prev;
            }
            else{
                head=head->next;
            }
        }
        return vec;
    }
};


/*
Combination of DLL + hashmap...
we have a head and tail already made by us whose key and value both are -1

unordered_map<int,Node*> mp,
we r storing key and the corresponding Node position so that we can go on that node without any hustle, to delete and insert it after head.

head ->next=tail
tail->prev=head
a current_size=0;
a total_size

:: deletion krte vakt node ko waste nhi krenge usko hi aise aage dal denge(in case of get func) OR uski hi values mein changes kr aage dal denge(in case of put func).
:: LRU se matlab hai, if capacity gets full and we want to add more node,we will delete the least used node
which is going to be always present at the position just before tail.
how its position is always there!?
because whenever we add some node, we gonna insert it after head.to keep it more fresh.
whenever we get some key,if it is present we gonna delete it and add it in the front, to make it fresh and then return its value
so in this way, the node at the position just before tail is kinda least used or old in comparison to other nodes.


get(){
  if node not present, then return -1,
  else 
    node ke position lo from map,usko delete karvao and ussi node 
    ko insert after head kro,
    then return its value.
}

put(){
  if node present, 
  node ke position lo from map,
  change its value , delete karvao and ussi node 
    ko insert after head kro,

  if node not present,
  two cases:-
  1. capacity full-
  get the position of node before tail with the help of tail pointer.
  uski key ko mp se erase krvao.
  then delete kro usko, delet krke curr mein uska return krdo taki curr after 
  function ussi node ko point kre jo delete huyi, so that hum ussi mein changes
   krke aage dalde, it will save our extra space of forming a new node.
   uss changed node ki key value map mein store krvana mat bhulna.

  2. capacity not full
  curr_sz++;
  new node bnano
  uski key values map mein store krvao.
  then insert it after head.
}
*/
class LRUCache {
public:
   class Node{
   public:
      int key;
      int val;
      Node* next;
      Node* prev;
      Node(int key,int val){
            this->key=key;
            this->val=val;
            next=prev=NULL;
      }
   };  
    unordered_map<int,Node*> mp;
    int sz;
    Node * head = new Node(-1, -1);
    Node * tail = new Node(-1, -1);

    int curr_sz=0;
    
    LRUCache(int capacity) {
        sz=capacity;
        head->next=tail;
        tail->prev=head;
        mp.clear();
    }

    Node* deletion(Node* &to_del){
           Node* ahead=to_del->next;
           Node* before=to_del->prev;
           before->next=ahead;
           ahead->prev=before;
           to_del->next=NULL;
           to_del->prev=NULL;
           return to_del;
    }
    void insert_after_head(Node* &curr){
        Node* ahead=head->next;
        curr->next=ahead;
        curr->prev=head;
        head->next=curr;
        ahead->prev=curr;
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;

        Node* curr=mp[key];
        curr=deletion(curr);
        insert_after_head(curr);
        return curr->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* curr=mp[key];
            curr->val=value;
            curr=deletion(curr);
            insert_after_head(curr);
        }
        else{
            if(curr_sz==sz){
                Node* curr=NULL;
                Node* to_del=tail->prev;
                mp.erase(to_del->key);
                curr=deletion(to_del);

                curr->key=key;
                curr->val=value;
                mp[key]=curr;

                insert_after_head(curr);
            }
            else{
                Node* new_node=new Node(key,value);
                mp[key]=new_node;
                insert_after_head(new_node);
                curr_sz++;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class Node{
    Node* freq[26];
    bool flag=false;
public:

    Node* contains(char ch){
        return freq[ch-'a'];
    }
    
    void mark(char ch,Node* node){
        freq[ch-'a']=node;
    }
    Node* get(char ch){
        return freq[ch-'a'];
    }
    void set_End(){
        flag=true;
    }
    bool get_End(){
        return flag;
    }
};

class Trie {
private: 
   Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(!node->contains(ch)){
                node->mark(ch,new Node());
            }
            node=node->get(ch);
        }
        node->set_End();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(!node->contains(ch)){
                return false;
            }
            node=node->get(ch);
        }
        return node->get_End();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            char ch=prefix[i];
            if(!node->contains(ch)){
                return false;
            }
            node=node->get(ch);
        }
        return true;
    }
};


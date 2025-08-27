#include <bits/stdc++.h> 
class Node{
    Node* freq[26];
    int cntWordsStarts=0;
    int cntWordsEnd=0;
public:
    Node* get(char ch){
        return freq[ch-'a'];
    }
    
    Node* contains(char ch){
        return freq[ch-'a'];
    }

    Node* put(char ch,Node* node){
        freq[ch-'a']=node;
    }

    void increaseWord(){
        cntWordsEnd++;
    }

    void increasePrefix(){
        cntWordsStarts++;
    }
    void decreaseWord(){
        cntWordsEnd--;
    }

    void decreasePrefix(){
        cntWordsStarts--;
    }

    int getEnd(){
        return cntWordsEnd;
    }

    int getStarts(){
        return cntWordsStarts;
    }

};
class Trie{
Node* root;
    public:

    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(!node->contains(ch)){
                node->put(ch,new Node());
            }
            node=node->get(ch);
            node->increasePrefix();
        }
        node->increaseWord();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(node->contains(ch)){
                node=node->get(ch);
            }
            else{
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(node->contains(ch)){
                node=node->get(ch);
            }
            else{
                return 0;
            }
        }
        return node->getStarts();
    }

    void erase(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(node->contains(ch)){
                node=node->get(ch);
                node->decreasePrefix();
            }
        }
        node->decreaseWord();
    }
};

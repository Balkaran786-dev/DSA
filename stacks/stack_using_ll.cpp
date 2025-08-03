#include<iostream>
using namespace std;
class Node{
public:
    Node* next;
    int val;

    Node(int value){
       val=value;
       next=NULL;
    }
};
class stack{
    int capacity;
    Node* head;
    int curr_size;
    public:
    stack(int size){
        this->capacity=size;
        head=NULL;
        this->curr_size=0;
    }
    bool isEmpty(){
        return this->head==NULL;
    }
    bool isFull(){
        return this->curr_size==this->capacity;
    }
    void push(int data){
        if(this->curr_size==this->capacity ){
            cout<<"overflow\n";
            return;
        }
        Node* new_node=new Node(data);
        new_node->next=this->head;
        this->head=new_node;
        this->curr_size++;
    }
    int pop(){
      if(this->head==NULL){
          cout<<"Underflow\n";
          return INT16_MIN;
      }
      Node* node_to_del=this->head;
      int result=node_to_del->val;
      this->head=this->head->next;
      this->curr_size--;
      free(node_to_del);
      return result;
    }
    int size(){
        return this->curr_size;
    } 
    int get_top(){
        if(this->head==NULL){
            cout<<"Underflow\n";
            return INT16_MIN;
        }
        return this->head->val;
    }
};
int main(){
    stack st(5);
    st.pop();
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.get_top()<<endl;
    st.push(4);
    st.push(5);
    cout<<st.get_top()<<endl;
    st.push(6);
    
    st.pop();
    st.pop();
    cout<<st.get_top()<<endl;
    return 0;
}
 
# include <iostream> 
using namespace std; 
 
class node{ 
    public: 
        int data; 
        node* next = NULL; 
        node(int d){ 
            data = d; 
        } 
}; 
 
class priority_queue{ 
    public: 
        int sz = 0; 
        node* front = NULL; 
        node* tail = NULL; 
 
        void push(int d){ 
            sz++; 
            if(front == NULL){ 
                front = tail =  new node(d); 
                return; 
            } 
 
            if(d <= front -> data){ 
                node* nnode = new node(d); 
                nnode -> next = front; 
                front = nnode; 
                return; 
            } 
 
            node* it = front; 
            node* prev = NULL; 
            while(it && (d > it -> data)){ 
                prev = it; 
                it = it -> next; 
            } 
            prev -> next = new node(d); 
            prev -> next -> next = it; 
            
        } 
 
        int top(){ 
            node* it = front; 
            if(!it) return -1; 
  
            while(it -> next) it = it -> next; 
            return it -> data; 
        } 
 
        void pop(){ 
            if(!front) return; 
            sz--; 
            node* prev = NULL; 
            node* it = front; 
            while(it -> next){ 
                prev = it; 
                it = it -> next; 
            } 
            delete it; 
            if(prev) prev -> next = NULL; 
            else front = NULL; 
        } 
 
        int size(){ 
            return sz; 
        } 
}; 
 
int main(){ 
    priority_queue pq; 
    bool ch = true; 
    pq.push(3); 
    pq.push(1); 
    pq.push(2); 
    pq.push(5); 
    pq.push(4); 
 
    // Printing the priority queue's top sequentially 
    while(pq.size() != 0){ 
        cout<<pq.top()<<" "; 
        pq.pop(); 
    } 
    cout<<endl; 
}
#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int key, degree;
    Node *parent, *child, *sibling;
    
    Node(int k) {
        key = k;
        degree = 0;
        parent = child = sibling = nullptr;
    }
};

class BinomialHeap {
private:
    Node* head;
    
    Node* mergeTrees(Node* a, Node* b) {
        if (a->key > b->key) swap(a, b);
        b->parent = a;
        b->sibling = a->child;
        a->child = b;
        a->degree++;
        return a;
    }
    
    Node* mergeHeaps(Node* h1, Node* h2) {
        if (!h1) return h2;
        if (!h2) return h1;
        
        Node* newHead = nullptr, *tail = nullptr;
        
        Node* a = h1;
        Node* b = h2;
        
        while (a && b) {
            Node* minNode;
            if (a->degree <= b->degree) {
                minNode = a;
                a = a->sibling;
            } else {
                minNode = b;
                b = b->sibling;
            }
            
            if (!newHead) {
                newHead = minNode;
                tail = minNode;
            } else {
                tail->sibling = minNode;
                tail = minNode;
            }
        }
        
        if (a) tail->sibling = a;
        if (b) tail->sibling = b;
        
        return newHead;
    }
    
    void adjustHeap() {
        if (!head) return;
        
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = curr->sibling;
        
        while (next) {
            if ((curr->degree != next->degree) || (next->sibling && next->sibling->degree == curr->degree)) {
                prev = curr;
                curr = next;
            } else {
                if (curr->key <= next->key) {
                    curr->sibling = next->sibling;
                    mergeTrees(curr, next);
                } else {
                    if (!prev) head = next;
                    else prev->sibling = next;
                    mergeTrees(next, curr);
                    curr = next;
                }
            }
            next = curr->sibling;
        }
    }
    
public:
    BinomialHeap() { head = nullptr; }
    
    void insert(int key) {
        Node* newNode = new Node(key);
        head = mergeHeaps(head, newNode);
        adjustHeap();
    }
    
    void display(Node* h) {
        while (h) {
            cout << "B" << h->degree << " Heap: ";
            Node* temp = h;
            while (temp) {
                cout << temp->key << " ";
                temp = temp->child;
            }
            cout << endl;
            h = h->sibling;
        }
    }
    
    void showHeap() {
        if (!head) {
            cout << "Heap is empty" << endl;
            return;
        }
        display(head);
    }
};

int main() {
    BinomialHeap bh;
    bh.insert(10);
    bh.insert(20);
    bh.insert(30);
    bh.insert(5);
    bh.insert(40);
    
    cout << "Binomial Heap after insertions:" << endl;
    bh.showHeap();
    
    return 0;
}

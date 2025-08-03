#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int key;
    int degree;
    Node* parent;
    Node* child;
    Node* left;
    Node* right;
    bool mark;
    
    Node(int k) {
        key = k;
        degree = 0;
        parent = child = nullptr;
        left = right = this;
        mark = false;
    }
};

class FibonacciHeap {
private:
    Node* minNode;
    int numNodes;
    
    void link(Node* y, Node* x) {
        y->left->right = y->right;
        y->right->left = y->left;
        y->parent = x;
        y->right = x->child;
        if (x->child)
            x->child->left = y;
        x->child = y;
        x->degree++;
        y->mark = false;
    }
    
    void consolidate() {
        if (!minNode) return;
        int maxDegree = log2(numNodes) + 1;
        Node* degreeArray[maxDegree] = {nullptr};
        
        Node* start = minNode;
        Node* x = minNode;
        do {
            Node* next = x->right;
            int d = x->degree;
            while (degreeArray[d]) {
                Node* y = degreeArray[d];
                if (x->key > y->key) swap(x, y);
                link(y, x);
                degreeArray[d] = nullptr;
                d++;
            }
            degreeArray[d] = x;
            x = next;
        } while (x != start);
        
        minNode = nullptr;
        for (int i = 0; i < maxDegree; i++) {
            if (degreeArray[i]) {
                if (!minNode || degreeArray[i]->key < minNode->key)
                    minNode = degreeArray[i];
            }
        }
    }
    
public:
    FibonacciHeap() {
        minNode = nullptr;
        numNodes = 0;
    }
    
    void insert(int key) {
        Node* newNode = new Node(key);
        if (!minNode) {
            minNode = newNode;
        } else {
            newNode->right = minNode;
            newNode->left = minNode->left;
            minNode->left->right = newNode;
            minNode->left = newNode;
            if (key < minNode->key)
                minNode = newNode;
        }
        numNodes++;
    }
    
    int getMin() {
        return minNode ? minNode->key : -1;
    }
    
    void extractMin() {
        if (!minNode) return;
        
        Node* child = minNode->child;
        if (child) {
            Node* start = child;
            do {
                child->parent = nullptr;
                child = child->right;
            } while (child != start);
        }
        
        if (minNode->right == minNode) {
            minNode = child;
        } else {
            minNode->left->right = minNode->right;
            minNode->right->left = minNode->left;
            minNode = minNode->right;
            consolidate();
        }
        numNodes--;
    }
    
    void showMin() {
        if (minNode)
            cout << "Minimum Key: " << minNode->key << endl;
        else
            cout << "Heap is empty" << endl;
    }
};

int main() {
    FibonacciHeap fh;
    fh.insert(10);
    fh.insert(5);
    fh.insert(20);
    fh.insert(15);
    
    cout << "Fibonacci Heap Min Element: ";
    fh.showMin();
    
    fh.extractMin();
    cout << "After Extracting Min: ";
    fh.showMin();
    
    return 0;
}
#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;
    
    Node(int data) {
        this->data = data;
        left = right = parent = nullptr;
        color = RED;
    }
};

class RedBlackTree {
private:
    Node *root;
    
    void rotateLeft(Node *&ptr) {
        Node *rightChild = ptr->right;
        ptr->right = rightChild->left;
        if (ptr->right)
            ptr->right->parent = ptr;
        rightChild->parent = ptr->parent;
        if (!ptr->parent)
            root = rightChild;
        else if (ptr == ptr->parent->left)
            ptr->parent->left = rightChild;
        else
            ptr->parent->right = rightChild;
        rightChild->left = ptr;
        ptr->parent = rightChild;
    }

    void rotateRight(Node *&ptr) {
        Node *leftChild = ptr->left;
        ptr->left = leftChild->right;
        if (ptr->left)
            ptr->left->parent = ptr;
        leftChild->parent = ptr->parent;
        if (!ptr->parent)
            root = leftChild;
        else if (ptr == ptr->parent->left)
            ptr->parent->left = leftChild;
        else
            ptr->parent->right = leftChild;
        leftChild->right = ptr;
        ptr->parent = leftChild;
    }

    void fixInsert(Node *&ptr) {
        Node *parent = nullptr;
        Node *grandparent = nullptr;
        while (ptr != root && ptr->color == RED && ptr->parent->color == RED) {
            parent = ptr->parent;
            grandparent = parent->parent;
            
            if (parent == grandparent->left) {
                Node *uncle = grandparent->right;
                if (uncle && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    ptr = grandparent;
                } else {
                    if (ptr == parent->right) {
                        rotateLeft(parent);
                        ptr = parent;
                        parent = ptr->parent;
                    }
                    rotateRight(grandparent);
                    swap(parent->color, grandparent->color);
                    ptr = parent;
                }
            } else {
                Node *uncle = grandparent->left;
                if (uncle && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    ptr = grandparent;
                } else {
                    if (ptr == parent->left) {
                        rotateRight(parent);
                        ptr = parent;
                        parent = ptr->parent;
                    }
                    rotateLeft(grandparent);
                    swap(parent->color, grandparent->color);
                    ptr = parent;
                }
            }
        }
        root->color = BLACK;
    }

public:
    RedBlackTree() { root = nullptr; }
    
    void insert(int data) {
        Node *newNode = new Node(data);
        if (!root) {
            root = newNode;
            root->color = BLACK;
            return;
        }
        
        Node *temp = root;
        Node *parent = nullptr;
        while (temp) {
            parent = temp;
            if (newNode->data < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        
        newNode->parent = parent;
        if (newNode->data < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
        
        fixInsert(newNode);
    }
    
    void inorderTraversal(Node *node) {
        if (!node) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
    
    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    RedBlackTree rbt;
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);
    rbt.insert(25);
    rbt.insert(5);
    rbt.insert(35);
    
    cout << "Inorder Traversal: ";
    rbt.inorder();
    
    return 0;
}

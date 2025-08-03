// BFS AND DFS in BST
#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *left;
    node *right;

    node(){
        left = NULL;
        right = NULL;
    }
    node(int data){
        this->data = data ;
        left = NULL;
        right = NULL;
    }
};

void insert(node * &root ,int ele){
    if(root == NULL){
        root = new node(ele);
        return;
    }
    node *temp = new node (ele);
    node *curr = root;
    node *par;
    while(curr != NULL){
        if (curr->data == ele) break;

        else if(curr->data > ele){
            // curr->left = temp;
            par = curr;
            curr = curr->left;
        }
        else{
            // curr->right = temp;
            par = curr;
            curr = curr->right;
        }
    }
    if(par->data > ele) par->left = temp;
    else par->right = temp;
}

void recursive_inorder(node* root){
    if (root == NULL) return;
    recursive_inorder(root->left);
    cout<<root->data<<" ";
    recursive_inorder(root->right);
}

void recursive_preorder(node* root){
    if (root == NULL) return;
    cout<<root->data<<" ";
    recursive_preorder(root->left);
    recursive_preorder(root->right);
}

void recursive_postorder(node* root){
    if (root == NULL) return;
    recursive_postorder(root->left);
    recursive_postorder(root->right);
    cout<<root->data<<" ";
}


void levelorder_traversal(node *root){
    queue <node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        if (temp == NULL){
            cout<<endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";

            if (temp->left){
                q.push(temp->left);
            } 
            if (temp->right){
                q.push(temp->right);
            } 
        }
    }
}

void iterative_preorder(node* root){
    stack<node*> st;
    if(root==NULL)return;
    st.push(root);
    while(!st.empty()){
        node* curr= st.top();
        st.pop();
        cout<<curr->data<<" ";
        if(curr->right!=NULL) st.push(curr->right);
        if(curr->left!=NULL) st.push(curr->left);
    }
}

int main(){
    cout<<"Name = BASANT"<<endl<<"Roll no. = 23103028"<<endl;
    node *root = NULL;
    
    insert(root,5); 
    insert(root,2); 
    insert(root,7); 
    insert(root,3); 
    insert(root,1); 
    insert(root,6); 
    insert(root,9); 

    cout<<"Recursive traversal of tree is: "<<endl;
    cout<<"inorder traveral: ";
    recursive_inorder(root);
    cout<<"\npreorder traveral: ";
    recursive_preorder(root);
    cout<<"\npostorder traveral: ";
    recursive_postorder(root);

    cout<<endl;
    cout<<"\niterative traversal of tree is: "<<endl;
    cout<<"\npreorder traveral: ";
    iterative_preorder(root);
    cout<<"\nlevelorder traveral: "<<endl;
    levelorder_traversal(root);
}












#include <bits/stdc++.h>
using namespace std;

// Function to find the shortest path using BFS
vector<int> shortestPathBFS(vector<vector<int>> &adj, int start, int end, int n) {
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        if (node == end) break;
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
    
    vector<int> path;
    for (int v = end; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    
    if (path[0] != start) return {};
    return path;
}

// Function to find the shortest path using DFS
void dfs(int node, int end, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &currentPath, vector<int> &shortestPath) {
    visited[node] = true;
    currentPath.push_back(node);
    
    if (node == end) {
        if (shortestPath.empty() || currentPath.size() < shortestPath.size()) {
            shortestPath = currentPath;
        }
    } else {
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, end, adj, visited, currentPath, shortestPath);
            }
        }
    }
    
    visited[node] = false;
    currentPath.pop_back();
}

vector<int> shortestPathDFS(vector<vector<int>> &adj, int start, int end, int n) {
    vector<bool> visited(n, false);
    vector<int> currentPath, shortestPath;
    dfs(start, end, adj, visited, currentPath, shortestPath);
    return shortestPath;
}

int main() {
    int n, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> edges;
    
    vector<vector<int>> adj(n);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int start, end;
    cout << "Enter start and end nodes: ";
    cin >> start >> end;
    
    vector<int> pathBFS = shortestPathBFS(adj, start, end, n);
    vector<int> pathDFS = shortestPathDFS(adj, start, end, n);
    
    if (!pathBFS.empty()) {
        cout << "Shortest path using BFS: ";
        for (int node : pathBFS) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found using BFS between " << start << " and " << end << endl;
    }
    
    if (!pathDFS.empty()) {
        cout << "Shortest path using DFS: ";
        for (int node : pathDFS) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found using DFS between " << start << " and " << end << endl;
    }
    return 0;
}




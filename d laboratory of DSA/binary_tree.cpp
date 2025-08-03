# include <iostream> 
# include <vector> 
# include <math.h> 
using namespace std; 
 
class node{ 
    public: 
        int data; 
        node* left = NULL; 
        node* right = NULL; 
        node(int d){ 
            data = d; 
        } 
}; 
 
int main(){ 
    cout<<"Enter height of binary tree: "; 
    int ht; cin>>ht; 
 
    cout<<"Enter -1 for a NULL value\n\n"; 
    vector<vector<int>> tree; 
    for(int i = 0; i < ht; i++){ 
        vector<int> lvl; 
        for(int j = 0; j < (int)pow(2,i); j++){ 
            int v; cin>>v; 
            lvl.push_back(v); 
        } 
        tree.push_back(lvl); 
    } 
 
    cout<<endl<<endl; 
    for(int i = 0; i < ht; i++){ 
        for(int j = 0; j < tree[i].size(); j++){ 
                cout<<tree[i][j]<<" "; 
        } 
        cout<<endl; 
    } 
} 

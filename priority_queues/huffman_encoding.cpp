//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node{
public:
    int val;
    Node* left;
    Node* right;
    
    Node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};

class cmp{
    public:
    bool operator()(Node* n1,Node* n2){
	        return n1->val>n2->val;
	}
};

class Solution
{
	public:
	  
	    void get_codes(Node* root,string temp,vector<string> &ans){
	        if(root==NULL){
	            return;
	        }
	        
	        if(!root->left && !root->right){
	            ans.push_back(temp);
	            return;
	        }
	        
	        get_codes(root->left,temp+'0',ans);
	        get_codes(root->right,temp+'1',ans);
	        return;
	    }
	    
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<Node*,vector<Node*>,cmp> pq;
		    for(int i=0;i<N;i++){
		        Node *temp=new Node(f[i]);
		        pq.push(temp);
		    }
		    
		    while(pq.size()!=1){
		        Node* n1=pq.top();
		        pq.pop();
		        Node* n2=pq.top();
		        pq.pop();
		        Node* n3=new Node(n1->val+n2->val);
		        n3->left=n1;
		        n3->right=n2;
		        
		        pq.push(n3);
		    }
		    Node* root=pq.top();
		    string temp="";
		    vector<string> ans;
		    get_codes(root,temp,ans);
		    return ans;
		}
};
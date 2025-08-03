#include<bits/stdc++.h>
using namespace std;
class Node{
public:
   int val;
   Node* left;
   Node* right;

   Node(int data){
    val=data;
    left=NULL;
    right=NULL;
   }
};
class Solution{
public:
    vector<vector<int>> dp; 
    int Trees_helper(int start,int end){
        if(start>end){
            return 1;
        }
        
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        
        int trees=0;
        for(int i=start;i<=end;i++){  //making all nodes from start to end as root node one by one
             int leftSubtrees=Trees_helper(start,i-1);
             int rightSubtrees=Trees_helper(i+1,end);
             
             trees+=leftSubtrees*rightSubtrees;
        }

        dp[start][end]=trees;
        return trees;
    }
    
    int formTrees(int n) {
        dp.resize(n+1);
        for(int i=0;i<n+1;i++){
            dp[i].resize(n+1,-1);
        }
        return Trees_helper(1,n);
    }
};
int main(){
    Solution s;
    cout<<s.formTrees(4);
    return 0;
}
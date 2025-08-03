class Solution {   //using dfs. 
public:
    void fun(TreeNode* root,int &maxi,int cnt,char ch){
        if(root==NULL) return;

        maxi=max(maxi,cnt);
        if(ch=='A' || ch=='L'){
            fun(root->left,maxi,cnt+1,'R');
            fun(root->right,maxi,1,'L');
        }
        else if(ch=='A' || ch=='R'){
            fun(root->right,maxi,cnt+1,'L');
            fun(root->left,maxi,1,'R');
        }
    }
    int longestZigZag(TreeNode* root) {
        int maxi=0;
        int cnt=0;
        char ch='A';  //'A'->means anything ,L'->i want left, 'R' -> i want right
        fun(root,maxi,0,ch);
        return maxi;
    }
};
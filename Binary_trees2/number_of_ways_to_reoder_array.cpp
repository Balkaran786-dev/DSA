//Number of ways to reorder array to get same BST
class Solution {
public:
    int MOD=1e9+7;
    vector<vector<int>> pascal;
    int fun(vector<int> nums,int n){
        if(n==0 || n==1 || n==2) return 1;

        vector<int> left,right;
        int root=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        int n1=left.size(),n2=right.size();
        int z=pascal[n-1][n1];
        int x=fun(left,n1),y=fun(right,n2);
        return (int)(1LL * z * x % MOD * y % MOD);  // Safely handle large multiplications using 64-bit arithmetic

    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        pascal.resize(n+1);  //made this to make the nCr calculation easy and fast.
        for(int i=0;i<=n;i++){
            pascal[i].resize(i+1);
            for(int j=0;j<=i;j++){
                if(j==0 || j==i) pascal[i][j]=1;
                else{
                    pascal[i][j]=(pascal[i-1][j]+pascal[i-1][j-1])%MOD;
                }
            }
        }

        return (fun(nums, n) - 1 + MOD) % MOD;  // Ensure result is non-negative
    }
};
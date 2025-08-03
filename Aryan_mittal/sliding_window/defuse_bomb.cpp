class Solution {
    public:
        vector<int> decrypt(vector<int>& code, int k) {
            int n=code.size();
            if(k==0){
                for(int i=0;i<n;i++){
                    code[i]=0;
                }
                return code;
            }
            int sum=0;
            int left_idx,right_idx;
            if(k<0){
                left_idx=n-abs(k);
                right_idx=n-1;
            }
            else{
                left_idx=1;
                right_idx=k;
            }
            vector<int> ans(n);
            for(int i=left_idx;i<=right_idx;i++) sum+=code[i];
            ans[0]=sum;
            for(int i=1;i<n;i++){
                sum-=code[left_idx];
                left_idx=(left_idx+1)%n;
                right_idx=(right_idx+1)%n;
                sum+=code[right_idx];
                ans[i]=sum;
            }
            return ans;
        }
    };
//explained in copy
class Solution {
public:
    void next(vector<int>& nums,vector<int> &nse,vector<int> &nge,int n){
        stack<int> st1; // nse
        stack<int> st2; // nge
        st1.push(0);
        st2.push(0);
        for(int i=1;i<n;i++){
            while(!st1.empty() && nums[i]<nums[st1.top()]){
                nse[st1.top()]=i;
                st1.pop();
            }
            st1.push(i);
            while(!st2.empty() && nums[i]>nums[st2.top()]){
                nge[st2.top()]=i;
                st2.pop();
            }
            st2.push(i);
        }
    }
    void prev(vector<int>& nums,vector<int> &pse,vector<int> &pge,int n){
        stack<int> st1; // pse
        stack<int> st2; // pge
        st1.push(n-1);
        st2.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st1.empty() && nums[i]<=nums[st1.top()]){
                pse[st1.top()]=i;
                st1.pop();
            }
            st1.push(i);
            while(!st2.empty() && nums[i]>=nums[st2.top()]){
                pge[st2.top()]=i;
                st2.pop();
            }
            st2.push(i);
        }
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int> nse(n,n),nge(n,n),pse(n,-1),pge(n,-1);
        next(nums,nse,nge,n);
        prev(nums,pse,pge,n);
        
        long long max_sum=0,min_sum=0;
        int min_right,min_left,max_right,max_left;
        for(int i=0;i<n;i++){
            min_right=nse[i]-i;
            min_left=i-pse[i];
            min_sum+=(min_right*min_left*1LL*nums[i]);

            max_right=nge[i]-i;
            max_left=i-pge[i];
            max_sum+=(max_right*max_left*1LL*nums[i]);
        }
        return max_sum-min_sum;
    }
};
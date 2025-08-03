//explained in copy..

class Solution {
public:
    int mod=1e9+7;
    vector<int> next_smaller(vector<int> &input,int n){
     vector<int> ans(n,n);
     stack<int> st;
     st.push(0);
     for(int i=1;i<n;i++){
        while(!st.empty() && input[i]<input[st.top()]){
            ans[st.top()]=i;
            st.pop();
        }
        st.push(i);
     }
     return ans;
    }
    vector<int> prev_smaller(vector<int> &input,int n){
       vector<int> ans(n,-1);
       stack<int> st;
       st.push(n-1); 
       for(int i=n-2;i>=0;i--){
           while(!st.empty() && input[i]<=input[st.top()]){
               ans[st.top()]=i;
               st.pop();
           }
           st.push(i);
       }
       return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        
        vector<int> nse=next_smaller(arr,n);
       
        vector<int> pse=prev_smaller(arr,n);
        int ans=0;
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            ans=(ans+(left*1LL*right*arr[i])%mod)%mod;
        }
        return ans;
    }
};
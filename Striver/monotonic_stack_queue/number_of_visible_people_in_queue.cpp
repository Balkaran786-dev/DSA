class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        st.push(0);
        vector<int> ans(n,0);
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[i]>heights[st.top()]){
                 ans[st.top()]++;
                 st.pop();
            }
            if(!st.empty()){
              ans[st.top()]++;
            }
            st.push(i);
        }
        return ans;
    }
};
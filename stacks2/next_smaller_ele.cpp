//::when we are on decreasing slope, next_smaller_ele=next ele only.
//::when we are on increasing slope, we need to wait till a decreasing slope comes.its not always going to happen that every waiting ele will get its nse.so,
//we will keep it in the stack till we get its nse.

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> next_greater_ele(vector<int> input){
    vector<int> ans(input.size(),-1);
    stack<int> st;
    st.push(0);
    for(int i=1;i<input.size();i++){
        while(!st.empty() && input[i]<input[st.top()]){
            ans[st.top()]=input[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
int main(){
    vector<int> input={4,6,3,1,0,9,5,6,7,3,2};
    vector<int> output=next_greater_ele(input);

    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
}

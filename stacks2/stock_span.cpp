//span of one day is the maximum number of consecutive days(from that day and backwards) whose stock quote is less than or equal to the current day

//matlab ek curr day ka span check karte waqt we will see uss din and uske piche kitne days ke baad usse jada value aaegi.
//so,ek ele ka jo bhi prev greater ele hai (curr index - uska index) is the span of a particular day.. 
 


#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> prev_greater_ele(vector<int> input){
    vector<int> ans(input.size());
    stack<int> st; 
    st.push(input.size()-1); 
    for(int i=input.size()-2;i>=0;i--){
        while(!st.empty() && input[i]>input[st.top()]){
            ans[st.top()]=st.top()-i; //(curr_ele-prev_greater_ele_idx)
            st.pop();  //since we found the prev greater of this ele,so we pop it out
        }
        st.push(i);  //abh eese andr dalenge so that hum eska prev greater ele idx find kr ske
    }
    while(!st.empty()){  //jinka prev greater ele exist nhi krta matlab,unke pechle saare din ginne jayenge including that day too.
        ans[st.top()]=st.top()+1;
        st.pop();
    }
    return ans;
}
int main(){
    vector<int> input={4,6,3,1,0,9,5,6,7,3,2};
    vector<int> output=prev_greater_ele(input);

    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
} 

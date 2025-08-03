#include<bits/stdc++.h>
using namespace std;
int precendence(char op){
    if(op=='^') return 3;
    else if(op=='*' || op=='/' || op=='%') return 2;
    else if(op=='+' || op=='-') return 1;
    else return -1;
}
string infix_to_post(string exp){
    string ans="";
    stack<char> st;
    for(int i=0;i<exp.size();i++){
        char curr=exp[i];
        if(curr=='('){
            st.push(curr);
        }
        else if(isdigit(curr)){
            ans.push_back(curr);
        }
        else if(curr==')'){
            while(st.top()!='('){
                 ans.push_back(st.top());
                 st.pop();
            }
            st.pop(); //removing the (
        }
        else if(curr==' '){
            continue;
        }
        else{
            while(!st.empty() && precendence(st.top())>=precendence(curr)){
                ans.push_back(st.top());
                st.pop();
            }
            st.push(curr);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main(){
    string infix_exp;
    cout<<"Enter the infix exp:- "<<endl;
    getline(cin,infix_exp);
    string post_exp=infix_to_post(infix_exp);
    cout<<"The postfix exp is:- "<<post_exp;
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//   stack<int> st;
//    vector<int> next_greater_ele_idx(vector<int> &height){
//         int n=height.size();
//         vector<int> ans(height.size(),n);
//         for(int i=0;i<n;i++){
//             while(!st.empty() && height[i]>=height[st.top()]){
//                 ans[st.top()]=i;
//                 st.pop();
//             }
//             st.push(i);
//         }
//         return ans;
//     }
//     int trap(vector<int>& height) {
//         int n=height.size();
//         vector<int> next_greater=next_greater_ele_idx(height);
        
//         int amount=0;
//         int i=0;
//         while(i<=n-1){
//               if(next_greater[i]!=n){
//                   int temp=(next_greater[i]-i-1)*height[i];
//                   int j;
//                   for(j=i+1;j<next_greater[i];j++){
//                         temp-=height[j];
//                   }
//                   i=j;
//                   amount+=temp;
//               }
//               else{
//                 i++;
//               }
//         }
//         return amount;
//     }
// };
// int main(){
//     Solution s;
//     vector<int> num={0,1,0,2,1,0,1,3,2,1,2,1};
//     vector<int> next_greater=s.next_greater_ele_idx(num);

//     for(int i=0;i<next_greater.size();i++){
//         cout<<next_greater[i]<<" ";
//     }
    
//     cout<<endl<<s.trap(num);
//     return 0;
// }
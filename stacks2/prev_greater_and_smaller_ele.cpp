// //for finding the prev_greater_ele: reverse the input array.
// //find its next greater ele array.reverse this array,this is your output. 
// #include<iostream>
// #include<stack>
// #include<vector>
// #include<algorithm>
// using namespace std;
// vector<int> next_greater_ele(vector<int> input){
//     vector<int> ans(input.size());
//     stack<int> st; //to store the ele that are waiting for increasing slope.
//     st.push(0); //pushing 0 index in stack;
//     for(int i=1;i<input.size();i++){
//         if(input[i]>input[i-1]){    //increasing slope
//             while(!st.empty()){     //jab tak stack khtam nhi hota
//                 if(input[i]>input[st.top()]){
//                  ans[st.top()]=input[i];
//                  st.pop();
//                 }
//                 else{              //may be stack element is greater than input[i].in that case,we just need to move out of the stack
//                     break;
//                 }
//             }
//             st.push(i);          //jo curr ele hain jiske sath hum comparison kar rhe hain,usse push kiya. 
//         }
//         else{
//            st.push(i);           //decreasing slope...
//         }
//     }
//     while(!st.empty()){          //jo ele stack mein rhe gye,wo increasing slope ka wait hee krte rhe,
//                                  //but increasing slope nhi aya..hence unka nge -1 rkh denge.
//         ans[st.top()]=-1;
//         st.pop();
//     }
//     return ans;

// }
// vector<int> prev_greater_ele(vector<int> input){
//     reverse(input.begin(),input.end());
//     vector<int> ans=next_greater_ele(input);
//     reverse(ans.begin(),ans.end());
//     return ans;
// }
// int main(){
//     vector<int> input={4,6,3,1,0,9,5,6,7,3,2};
//     vector<int> output=prev_greater_ele(input);

//     for(int i=0;i<output.size();i++){
//         cout<<output[i]<<" ";
//     }
// } 

// //------------------------------------------------------------------------------------
// //similarly,for finding the prev_smaller_ele: reverse the input array.
// //find its next_smaller_ele array.reverse this array,this is your output. 



// //2nd approach to find prev greater ele
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> prev_greater_ele(vector<int> input){
    vector<int> ans(input.size(),-1);
    stack<int> st; 
    st.push(input.size()-1); 
    for(int i=input.size()-2;i>=0;i--){
        while(!st.empty() && input[i]>input[st.top()]){
            ans[st.top()]=input[i];
            st.pop();
        }
        st.push(i);
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



// //prev smaller
// #include<iostream>
// #include<stack>
// #include<vector>
// #include<algorithm>
// using namespace std;
// vector<int> prev_smaller_ele(vector<int> input){
//     vector<int> ans(input.size(),-1);
//     stack<int> st; 
//     st.push(input.size()-1); 
//     for(int i=input.size()-2;i>=0;i--){
//         while(!st.empty() && input[i]<input[st.top()]){
//             ans[st.top()]=input[i];
//             st.pop();
//         }
//         st.push(i);
//     }
    
//     return ans;

// }
// int main(){
//     vector<int> input={4,6,3,1,0,9,5,6,7,3,2};
//     vector<int> output=prev_smaller_ele(input);

//     for(int i=0;i<output.size();i++){
//         cout<<output[i]<<" ";
//     }
// }




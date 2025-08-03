//bruteforce solution: 
//at every index,you start checking from one ahead ele if it is greater than the curr ele
//,if it is,you store that greater ele in the output array.you move forward your curr_ele.
//do this till the end of your array.

// #include<iostream>   //space complexity-o(n) time complexity-o(n**2)
// #include<vector>
// using namespace std;
// vector<int> next_greater_ele(vector<int> input){
//     vector<int> ans(input.size(),-1);
//     for(int i=0;i<input.size();i++){
//          for(int j=i+1;j<input.size();j++){
//             if(input[j]>input[i]){
//                 ans[i]=input[j];
//                 break;
//             }
//          }
//     }
//     return ans;
// }
// int main(){
//     vector<int> input={4,5,9,1,5,2,7,1};
//     vector<int> output=next_greater_ele(input);

//     for(int i=0;i<output.size();i++){
//         cout<<output[i]<<" ";
//     }
// } 



//::when we are on increasing slope, next_greater_ele=next ele only.
//::when we are on decreasing slope, we need to wait till a increasing slope comes.its not always going to happen that every waiting ele will get its nge.so,
//we will keep it in the stack till we get its nge.
//::-----------whenever we are making something to wait,we actually store it in stack------------------
//::also, here we would need to ACCESS the last added ele in waiting area which is the prop of stack.


//for example, 2 3 7 4 2 3  here 7 4 2 are on decresing slope, 3 is on increasing,3 will
//only be a nge for 2,not for any other ele.hence,at least the top element of the waiting area will definitely get nge if there is an increasing slope after it.
 

//we will store the index of the ele in the stack,beacuse from index we can get ele, but from ele we can't get index
//we will push the first ele index in the stack,
//we start with the second ele,it is >first ele, we pop out the 
//first ele index and in the output array,we fix output_arr=arr[2];
//we will push the second ele index in the stack.if there is increasing slope,
//same above procedure will be followed.if there will be decreasing slope,we will keep pushing the ele
//in the stack till we get the ele that is greater from prev ele.At this point,we check in the stack for how many ele,this greater ele is the nge.till either our stack gets empty or ele in the stck is higher than the greater ele.
//after then,we will again push this greater ele in the stack.



#include<iostream>
#include<stack> //time complexity-o(n)  space-o(n)....
#include<vector>
using namespace std;
vector<int> next_greater_ele(vector<int> input){
    vector<int> ans(input.size());
    stack<int> st; //to store the ele that are waiting for increasing slope.
    st.push(0); //pushing 0 index in stack;
    for(int i=1;i<input.size();i++){
        while(!st.empty() && input[i]>input[st.top()]){
            ans[st.top()]=input[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){          //jo ele stack mein rhe gye,wo increasing slope ka wait hee krte rhe,//but increasing slope nhi aya..hence unka nge -1 rkh denge.
        ans[st.top()]=-1;
        st.pop();
    }
    return ans;
}
int main(){
    vector<int> input={5,4,3,2,1};
    vector<int> output=next_greater_ele(input);

    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
} 
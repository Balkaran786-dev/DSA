// #include<iostream>
// #include<stack>
// using namespace std;
// stack<int> copy(stack<int> &input){ //we don't want to create any copy,so we r pass by referencing
//      stack<int> temp;
//      while(input.empty()!=true){ //till the time input stack doesn't get empty,keep doing this process
//         int curr=input.top();
//         input.pop();
//         temp.push(curr);
//      }
 
//      while(temp.empty()!=true){
//         int curr=temp.top();
//         temp.pop();
//         input.push(curr);
//      }
//      return input;
// }
// int main(){
//     stack<int>st1;
//     st1.push(1);
//     st1.push(2);
//     st1.push(3);
//     st1.push(4);
//     stack<int> st2=copy(st1);
//     while(st2.empty()!=true){
//         cout<<st2.top()<<endl;;
//         st2.pop();
//     }
//     return 0;
// }


//by recursion,we will here use call stack in place of temp;

#include<iostream>
#include<stack>
using namespace std;
void copy(stack<int> &st1,stack<int> &result){
    if(st1.empty()){
        return;
    }
    int curr=st1.top();
    st1.pop();
    copy(st1,result);
    result.push(curr);
}
int main(){
    stack<int>st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    stack<int> result;
    copy(st1,result);
    while(result.empty()!=true){
        cout<<result.top()<<endl;;
        result.pop();
    }
    return 0;
}
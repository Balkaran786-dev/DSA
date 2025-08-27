// #include<iostream>
// #include<stack>
// using namespace std;
// void reverse(stack<int> &input){  //timecomplexity-o(3n)~o(n)  spacecomplexity-o(n);
//      stack<int> temp1;
//      while(!input.empty()){
//         int curr=input.top();
//         temp1.push(curr);
//         input.pop();
//      }
//      stack<int> temp2;
//      while(!temp1.empty()){
//         int curr=temp1.top();
//         temp2.push(curr);
//         temp1.pop();
//      }
//     while(!temp2.empty()){
//         int curr=temp2.top();
//         input.push(curr);
//         temp2.pop();
//      }
// }
// int main(){
//     stack<int> st1;
//     st1.push(1);
//     st1.push(2);
//     st1.push(3);
//     st1.push(4);
//     st1.push(5);

//      reverse(st1);
//      while(!st1.empty()){
//         cout<<st1.top()<<endl;
//         st1.pop();
//      }
//     return 0;
// }



//by recursion. our time complexity is increased
#include<iostream>
#include<stack>
using namespace std;
void insert_at_bottom(stack<int> &input,int x){ 
     stack<int> temp;
     while(input.empty()!=true){ //till the time input stack doesn't get empty,keep doing this process
        int curr=input.top();
        input.pop();
        temp.push(curr);
     }
     input.push(x);
     while(temp.empty()!=true){
        int curr=temp.top();
        temp.pop();
        input.push(curr);
     }
}
void reverse(stack<int> &input){  //timecomplexity-o(n**2)  spacecomplexity-o(n);
     if(input.empty()){
        return;
     }
     int curr=input.top();
     input.pop();
     reverse(input);
     insert_at_bottom(input,curr);
}
int main(){
    stack<int> st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);
     reverse(st1);
     while(!st1.empty()){
        cout<<st1.top()<<endl;
        st1.pop();
     }
    return 0;
}

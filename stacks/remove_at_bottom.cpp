// #include<iostream>
// #include<stack>
// using namespace std;
// void remove_at_bottom(stack<int> &input){ //we don't want to create any copy stack,so we r pass by referencing
//      stack<int> temp;
//      while(input.size()!=1){ //till the time input stack doesn't remove all the elements above the req idx,keep doing this process
//         int curr=input.top();
//         input.pop();
//         temp.push(curr);
//      }
//      input.pop();
//      while(!temp.empty()){
//         int curr=temp.top();
//         temp.pop();
//         input.push(curr);
//      }
// }
// int main(){
//     stack<int>st1;
//     st1.push(1);
//     st1.push(2);
//     st1.push(3);
//     st1.push(4);
    
//     remove_at_bottom(st1);
//     while(st1.empty()!=true){
//         cout<<st1.top()<<endl;;
//         st1.pop();
//     }
//     return 0;
// }

#include<iostream>
#include<stack>
using namespace std;
void remove_at_bottom(stack<int> &st1){
    if(st1.size()==1){
        st1.pop();
        return;
    }
    int curr=st1.top();
    st1.pop();
    remove_at_bottom(st1);
    st1.push(curr);
}
int main(){
    stack<int> st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    remove_at_bottom(st1);
    while(st1.empty()!=true){
        cout<<st1.top()<<endl;
        st1.pop();
    }
    
    return 0;
}
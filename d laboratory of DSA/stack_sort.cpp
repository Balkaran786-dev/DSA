#include<iostream>
#include<stack>
using namespace std;
stack<int> sort(stack<int> &st){
    stack<int> sorted;
    stack<int> temp;
    while(!st.empty()){
        int ele=st.top();
        st.pop();
        while(!sorted.empty() && ele<=sorted.top()){
            temp.push(sorted.top());
            sorted.pop();
        }
        sorted.push(ele);
        while(!temp.empty()){
            sorted.push(temp.top());
            temp.pop();
        }
    }
    return sorted;
}
int main(){
    stack <int> st;
    int n;
    cout<<"Enter the number of elements you want in the stack:- ";
    cin>>n;
    while(n--){
        int val;
        cin>>val;
        st.push(val);
    }
    stack<int> sorted_stack=sort(st);
    while(!sorted_stack.empty()){
        cout<<sorted_stack.top()<<endl;
        sorted_stack.pop();
    }
    return 0;
}
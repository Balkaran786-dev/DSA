#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void reverse(queue<int> &qu,stack <int> &st){
    if(qu.empty()){
        return;
    }
    int ele=qu.front();
    st.push(ele);
    qu.pop();
    reverse(qu,st);
    qu.push(st.top());
    st.pop();
}
int main(){
    queue<int> qu;
    stack<int> st;

    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    reverse(qu,st);
    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    return 0;
}
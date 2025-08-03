#include<bits/stdc++.h>
using namespace std;
class MyStack {   
public:
    queue<int> qu;
    MyStack() {
    }
    
    void push(int x) {
        queue<int> temp;
        while(!qu.empty()){
            temp.push(qu.front());
            qu.pop();
        }
        qu.push(x);
        while(!temp.empty()){
            qu.push(temp.front());
            temp.pop();
        }
    }
    
    int pop() {
       int ele=qu.front();
       qu.pop();
       return ele;
    }
    
    int top() {
        return qu.front();
    }
    
    bool empty() {
        return qu.empty();
    }
};
int main(){
    MyStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.pop()<<endl;
    cout<<st.top()<<endl;
    cout<<st.empty()<<endl;
    return 0;
}
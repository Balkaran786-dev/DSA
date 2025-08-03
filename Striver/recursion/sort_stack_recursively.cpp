// to sort stack iteratively so that we have sorted ele in our own stack:-
// we require two extra stacks,
// in first, we will put all the eles from our original stacks to empty our original stack
// then from this first stack, we start pushing ele in a sorted manner in orginal stack using second stack



//while recursion, the role of the first stack is played by the inbuilt recursion stack...

// o(n^2) time complexity in worst case if ele are present in increasing order..
// o(n)+o(n) space.
void insert_in_sorted_order(stack<int> &st,int value){
    stack<int> temp;
    while(!st.empty() && st.top()>value){
        temp.push(st.top());
        st.pop();
    }
    
    st.push(value);
    
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}
void sort_stack(stack<int> &st){
    if(st.empty()) return;
    
    int ele=st.top();
    st.pop();
    sort_stack(st);
    insert_in_sorted_order(st,ele);
}
void SortedStack :: sort()
{
   //Your code here
   sort_stack(s);
   
}
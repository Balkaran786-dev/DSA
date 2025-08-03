// #include<iostream>
// #include<stack>
// using namespace std;
// void insert_at_bottom(stack<int> &input,int idx,int value){ //we don't want to create any copy stack,so we r pass by referencing
//      stack<int> temp;
//      int ele_to_remove=input.size()-idx;
//      while(ele_to_remove--){ //till the time input stack doesn't remove all the elements above the req idx,keep doing this process
//         int curr=input.top();
//         input.pop();
//         temp.push(curr);
//      }
//      input.push(value);
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
//     int idx,value;
//     cout<<"the index where you want to insert:";
//     cin>>idx;
//     cout<<"The value you want to insert:";
//     cin>>value;
//     insert_at_bottom(st1,idx,value);
//     while(st1.empty()!=true){
//         cout<<st1.top()<<endl;;
//         st1.pop();
//     }
//     return 0;
// }

#include<iostream>
#include<stack>
using namespace std;
void insert_at_idx(stack<int> &st1,int ele_to_remove,int value){
    if(ele_to_remove==0){
        st1.push(value);
        return;
    }
    int curr=st1.top();
    st1.pop();
    insert_at_idx(st1,--ele_to_remove,value); //when you are post decrementing,same value was passed to the next function call.
    st1.push(curr);
}
int main(){
    stack<int> st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    int idx,value;
    cout<<"the index where you want to insert:";
    cin>>idx;
    cout<<"The value you want to insert:";
    cin>>value;
    int ele_to_remove=st1.size()-idx;
    insert_at_idx(st1,ele_to_remove,value);
    while(st1.empty()!=true){
        cout<<st1.top()<<endl;
        st1.pop();
    }
    
    return 0;
}
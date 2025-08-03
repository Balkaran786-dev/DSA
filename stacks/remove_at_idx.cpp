// #include<iostream> //0 based indexing is assumed
// #include<stack>
// using namespace std;
// void remove_at_idx(stack<int> &input,int idx){ //we don't want to create any copy stack,so we r pass by referencing
//      stack<int> temp;
//      int ele_to_remove=input.size()-idx-1;
//      if(ele_to_remove>=0){
//          while(ele_to_remove--){ //till the time input stack doesn't remove all the elements above the req idx,keep doing this process
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
//      }
//      else{   //if index is greater than size of stack
//         cout<<"index is out of range"<<endl;
//      }
    
// }
// int main(){
//     stack<int>st1;
//     st1.push(1);
//     st1.push(2);
//     st1.push(3);
//     st1.push(4);
//     st1.push(5);
//     int idx;
//     cout<<"the index of the ele you want to remove:";
//     cin>>idx;
//     remove_at_idx(st1,idx);
//     while(st1.empty()!=true){
//         cout<<st1.top()<<endl;;
//         st1.pop();
//     }
//     return 0;
// }

#include<iostream>
#include<stack>
using namespace std;
void remove_at_idx(stack<int> &st1,int ele_to_remove){
    if(ele_to_remove==0){
        st1.pop();
        return;
    }
    int curr=st1.top();
    st1.pop();
    remove_at_idx(st1,--ele_to_remove);
    st1.push(curr);
}
int main(){
    stack<int> st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);
    int idx;
    cout<<"the index of ele which you want to remove:";
    cin>>idx;
    int ele_to_remove=st1.size()-idx-1;
    if(ele_to_remove>=0){
        remove_at_idx(st1,ele_to_remove);
        while(!st1.empty()){
        cout<<st1.top()<<endl;
        st1.pop();
        }
    }
    else{
        cout<<"index is out of range";
    }
   
    return 0;
}
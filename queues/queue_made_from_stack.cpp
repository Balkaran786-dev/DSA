/*we need to implement push and pop operations on queue using stack internally.
  TWO TYPES:
  @Push efficient: in which push operation is of o(1),pop operation can be bad.
  @Pop efficient:in which pop operation is of o(1),push operation can be bad.*/

//IMPLEMENTING PUSH EFFICIENT QUEUE USING STACK:
// #include<iostream>
// #include<stack>
// using namespace std;
// class queue{
//      stack<int> st;

//      public:
//      void push_ele(int data){
//         st.push(data);
//      }

//      void pop_ele(){     
//         if(st.empty()) return;
//         stack<int> temp;
//         while(st.size()!=1){
//             temp.push(st.top());
//             st.pop();
//         }
//         st.pop();
//         while(!temp.empty()){
//             st.push(temp.top());
//             temp.pop();
//         }
//      }
//      int front(){
//         if(st.empty()) return INT16_MIN;
//         stack<int> temp;
//         while(st.size()!=1){
//             temp.push(st.top());
//             st.pop();
//         }
//         int ans=st.top();
//         while(!temp.empty()){
//             st.push(temp.top());
//             temp.pop();
//         }
//         return ans;
//      }
//      bool empty(){
//         return st.empty();
//      }
// };
// int main(){
//     queue qu;
//     qu.push_ele(1);   //Enqueue
//     qu.push_ele(2);
//     qu.push_ele(3);
//     qu.push_ele(4);
//     qu.pop_ele();     //dequeue
//     while(!qu.empty()){
//         cout<<qu.front()<<" ";
//         qu.pop_ele();
//     }
//     return 0;
// } 


//IMPLEMENTING PULL EFFICIENT QUEUE USING STACK:
#include<iostream>
#include<stack>
using namespace std;
class queue{
     stack<int> st;

     public:
     void push_ele(int data){
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        st.push(data);
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
     }

     void pop_ele(){     
        st.pop();
     }
     int front(){
        if(st.empty()) return INT16_MIN;
        return st.top();
     }
     bool empty(){
        return st.empty();
     }
};
int main(){
    queue qu;
    qu.push_ele(1);   //Enqueue
    qu.push_ele(2);
    qu.push_ele(3);
    qu.push_ele(4);
    qu.pop_ele();     //dequeue
    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop_ele();
    }
    return 0;
}
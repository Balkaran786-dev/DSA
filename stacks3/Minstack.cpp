/*approach 1: bruteforce solution-o(n) both time and space complexity: when you need to find min ele,you need to read the whole stack.
  you maintain a min_ele variable.you keep reading the top ele in the stack and comparing it with the prev min ele,before poping out,you store the top ele 
  in another stack and then you pop out it.In this way,you maintain an additional stack of size n.
  */

/*approach 2 -o(n) for space complexity and o(1) for time complexity: you need to push[7,4,5,2,9,8,1]  
  you need to maintain two stack,1. original stack that contains original elements. 2.side stack whose top gives us the min of all the elements stored in the stack.

  hum stack 1 mein toh sath ke sath normally elements push krte rhenge lekin 2nd stack mein conditions ke according elements ko dalenge.
  when you push 1st ele in 1st,push it in 2nd too. when you push second ele in 1st stack,check if it is
  smaller than the top ele of 2nd stack,if yes push second ele in the 2nd stack,otherwise push the top ele again in the stack.
  when you pop out the ele from 1st stack,you must do it from 2nd stack too.*/
  /*push 7 in both,push 4 in both,push 5 in 1st and 4 in 2nd, push 2 in both,push 9 in 1st and 2 in 2nd,
  push 8 in 1st and 2 in 2nd,push 1 in both...*/


/*Approach 3:(only for positive values) you maintain a variable min_ele initialised with INT_MAX.When you push your first ele,change the value of min_ele from INT_MAX to first ele.
  when you push second ele,if it is less than min_ele,push (second ele-min_ele) in stack and then changes the min_ele to that second ele value.if the second comes out to be greater than the min_ele,
  you normally push the value in stack without changing the min_ele.
  when you pop out any ele,if it greater than 0,pop it normally,but if it is lesser than 0,there must have been a change in the min_ele during pushing this negative value.
  hence, change the min_ele to old min ele as:
  int old_min=min_ele-st.top();    //y=x-min_ele  y-that we had inserted in the stack,x-value of ele that needed to be insert which.also we change min_ele to that x.
  min_ele=old_min;                 //so to get (old_min=y-x)
  st.pop();
  */


/*previous approach was just for positive values.for example,At some point,your min_ele=-5. your next ele=-1, as -1>-5,so we add it as it is.
 but during poping  it,since it is less than 0,we tend to change the min_ele which is not correct.
 Approach 4:
 while pushing a ele,whether it is greater than or smaller than min_ele ,we always going to push value-min_ele.IN the above example,we add -1-(-5)=4 in the stack.
*/


#include<iostream> //o(1) both time and space complexity
#include<stack>
using namespace std;
#define ll long long int
class Minstack{
      stack<int> st;
      ll min_ele;
      public:
      Minstack(){
        min_ele=INT16_MAX;
      }
      void push_ele(int val){
        if(st.empty()){
            st.push(val);
            min_ele=val;
        }
        else if(val>min_ele){
            st.push(val-min_ele);
        }
        else if(val<min_ele){
            st.push(val-min_ele);
            min_ele=val;
        }
        else if(val==min_ele){
            st.push(val-min_ele);
        }
      }
     
     void pop_ele(){
        if(st.size()==1){
            st.pop();
        }
        else if(st.top()>=0){
            st.pop();
        }
        else if(st.top()<0){
            ll old_min=min_ele-st.top();
            min_ele=old_min;
            st.pop();
        }
     }
     int top(){
        if(st.top()>=0){
          return st.top()+min_ele;
        }
        else if(st.top()<0){
          ll old_min=min_ele-st.top();
          return st.top()+old_min;
        }
     }
     int get_min(){
        return min_ele;
     }
};
int main(){
    Minstack mst;
    mst.push_ele(10);
    mst.push_ele(5);
    cout<<mst.top()<<endl;
    mst.push_ele(5);
    mst.push_ele(12);
    cout<<mst.get_min()<<endl;
    cout<<mst.top()<<endl;
    mst.push_ele(-1);
    mst.push_ele(-5);
    cout<<mst.top()<<endl;
    mst.pop_ele();
    cout<<mst.top()<<endl;
    cout<<mst.get_min()<<endl;
}
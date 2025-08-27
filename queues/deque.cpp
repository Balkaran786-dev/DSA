//In deque,we can remove as well as add from both sides.

//push_back:adds an element from back side of queue
//push_front:adds an element from front side of queue
//pop_front:removes an element from front side of queue
//pop_back: removes an element from back side of queue
//front:returns the first element of queue.
//size: return no. of elements of queue


#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);
    dq.push_front(0);
    dq.push_front(33);
    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    } 

    //take away task : 
    //implement:
    //deque and its function like,pop_back,push_front,push_back,pop_front.etc

    return 0;
}
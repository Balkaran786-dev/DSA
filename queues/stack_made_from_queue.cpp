// class MyStack {   //push effecient
// public:
//     queue<int> qu;
//     MyStack() {
//     }
    
//     void push(int x) {
//         qu.push(x);
//     }
    
//     int pop() {
//         if(qu.empty())return INT_MIN;
//         queue<int> temp;
//         while(qu.size()!=1){
//             temp.push(qu.front());
//             qu.pop();
//         }
//         int ele=qu.front();
//         qu.pop();
//         while(!temp.empty()){
//             qu.push(temp.front());
//             temp.pop();
//         }
//         return ele;
//     }
    
//     int top() {
//         if(qu.empty())return INT_MIN;
//         queue<int> temp;
//         while(qu.size()!=1){
//             temp.push(qu.front());
//             qu.pop();
//         }
//         int ele=qu.front();
//         qu.pop();
//         temp.push(ele);
//         while(!temp.empty()){
//             qu.push(temp.front());
//             temp.pop();
//         }
//         return ele;
//     }
    
//     bool empty() {
//         return qu.empty();
//     }
// };

//pop effecient

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
#include<iostream>
using namespace std;
class stack{
    int capacity;
    int* arr;
    int top;
    public:
    stack(int c){
        capacity=c;
        arr=new int(c);  //dynamic memory allocation
        top=-1;
    }

    void push(int data){
        if(top==capacity-1){
            cout<<"Overflow"<<endl;
            return;
        }
        top++;  //increasing the top_idx by 1
        arr[top]=data;  //putting data to array
        
    }

    int pop(){
        if(top==-1){
            cout<<"underflow\n";
            return INT16_MIN;
        }
        return arr[top--];
    }

    int get_top(){
        if(top==-1){
           cout<<"Underflow\n";
           return INT16_MIN;
        }
        return arr[top];
    }

    bool isEmpty(){
        return top==-1;
    }
    int size(){
        return top+1;
    }
    bool isFull(){
        return top==capacity-1;
    }
};
int main(){
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.get_top()<<endl;
    st.push(4);
    st.push(5);
    cout<<st.get_top()<<endl;
    st.push(6);
    
    st.pop();
    st.pop();
    cout<<st.get_top()<<endl;


    return 0;
}
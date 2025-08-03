//reverse polish notation or postfix notation
//operands needs to wait till an operator comes that operates on last two digits.

#include<iostream>
#include<stack>
#include<string>
#include<math.h>
using namespace std;
int calu(int v1,int v2,char ch){
    if(ch=='^'){
        return pow(v1,v2);
    }
    else if(ch=='+'){
        return v1+v2;
    }
    else if(ch=='*'){
        return v1*v2;
    }
    else if(ch=='/'){
        return v1/v2;
    }
    else{
        return v1-v2;
    }
}
int calc_postfix(string str){
    stack<int> st;  //to store the operands
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(isdigit(ch)){
            st.push(ch-'0');
        }
        else{
            int v2=st.top();
            st.pop();
            int v1=st.top();
            st.pop();
            st.push(calu(v1,v2,ch));
        }
    }
    return st.top();
}
int main(){
    string str;
    cin>>str;
    cout<<calc_postfix(str);
    
    return 0;
}
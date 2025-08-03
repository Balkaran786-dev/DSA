//polish notation
//evaluation of prefix is similar to to postfix just you need to traverse the string from backwards
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
    for(int i=str.size()-1;i>=0;i--){
        char ch=str[i];
        if(isdigit(ch)){
            st.push(ch-'0');
        }
        else{
            int v1=st.top();  //isme jo upper hoga usse v1 consider krna
            st.pop();
            int v2=st.top();  //and jo neeche hoga usse v2 consider krna
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
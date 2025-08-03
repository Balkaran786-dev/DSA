#include<bits/stdc++.h>
using namespace std;
string postfix_to_pre(string &str){
        string ans="";
        stack<string> st;
        for(int i=0;i<str.size();i++){
            char ch=str[i];
            string temp="";
            temp.push_back(ch);
            if(isdigit(ch)){
                st.push(temp);
            }
            else{  //means it is a operator
                string v1=st.top();
                st.pop();
                string v2=st.top();
                st.pop();
                st.push(temp+v2+v1);
            }
        }
        return st.top();
}
int main(){
    string str;
    cin>>str;
    string ans=postfix_to_pre(str);
    cout<<ans;
    return 0;
}
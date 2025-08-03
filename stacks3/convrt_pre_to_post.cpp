#include<bits/stdc++.h>
using namespace std;
string prefix_to_post(string &str){
        string ans="";
        reverse(str.begin(),str.end());
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
                st.push(v1+v2+temp);
            }
        }
        return st.top();
}
int main(){
    string str;
    cin>>str;
    string ans=prefix_to_post(str);
    cout<<ans;
    return 0;
}
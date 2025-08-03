// //stoi()--converts string to integer  to_string()--converts integer to string
// //string.back()--basically returns last element of string.
// //string.push_back(char)--to add a character
// //string.popback()--to remove the last character.
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;   //time and space complexity--o(length of decoded string)
// int main(){
//     string s;
//     cin>>s;
//     string result="";
//     //reading the string
//     for(int i=0;i<s.size();i++){
//          if(s[i]!=']'){
//            result.push_back(s[i]);
//          }
//          else{

//             //extracting the str from result
//             string str="";
//             while(!result.empty() && result.back()!='['){
//                 str.push_back(result.back());   //inserting the charcaters in the str
//                 result.pop_back();              //side by side,we removing them from result.
//             }

//             //reversing the string
//             reverse(str.begin(),str.end());

//             //removing the last character from result which is '['
//             result.pop_back();

//             //extracting the num from result
//             string num="";
//             while(!result.empty() && result.back()>='0' && result.back()<='9'){
//                 num.push_back(result.back());
//                 result.pop_back();
//             }

//             //reversing the num
//             reverse(num.begin(),num.end());

//             //converting the num from string to integer.
//             int no_of_times=stoi(num);
            
//             //inserting str in result a specific no_of_times. 
//             while(no_of_times){
//                 result+=str;
//                 no_of_times--;
//             }
//          }
//     }

//     cout<<result;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
string decode(string &str){
    string ans="";
    stack<string> st;
    for(int i=0;i<str.size();i++){
        char curr=str[i];
        string temp1="";
        temp1+=curr;
        if(curr==']'){
            string temp2="";
           while(st.top()!="["){
               temp2+=st.top();
               st.pop();
           }
           st.pop();   //removing the closing bracket
           int count=stoi(st.top()); //count of times
           st.pop();
           string to_add=temp2;
           while(--count){
            temp2+=to_add;
           }
           if(st.empty()){
            reverse(temp2.begin(),temp2.end());
            ans+=temp2;
           }
           else{
            st.push(temp2);
           }
        }
        else{
            st.push(temp1);
        }
    }
    string left_out="";
    while(!st.empty()){
       left_out+=st.top();
       st.pop();
    }
    reverse(left_out.begin(),left_out.end());
    ans+=left_out;
    return ans;
}
int main(){
    string str="2[abc]3[cd]ef";
    string res=decode(str);
    cout<<res;
    return 0;
}
#include<iostream>  //assume only parenthesis are allowed
#include<stack>
using namespace std;
// int remove_bracket(string str){
//     stack<char> st;
//     int count=0;
//     for(int i=0;i<str.size();i++){
//         char ch=str[i];
//         if(ch=='('){
//             st.push(ch);
//         }
//         else{
//             if(!st.empty()){
//                 st.pop();
//             }
//             else{
//                 count++;
//             }
//         }
//     }
//     while(!st.empty()){
//         count++;
//         st.pop();
//     }
//     return count;
// }  //No need of stack for this parenthesis only
int remove_bracket(string str){
   int ans=0;
   int counter=0;
   for(int i=0;i<str.size();i++){
    if(str[i]=='('){
        counter++;
    }
    else{
        if(counter>0){
            counter--;
        }
        else{
            ans++;
        }
    }
   }

   return ans+counter;
}
int main(){
    string str;
    cout<<"The string:";
    cin>>str;
    cout<<remove_bracket(str);
}
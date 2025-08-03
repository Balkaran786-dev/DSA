//hum kya karenge ki jo opening brackets hain vo waiting state mein rhenege,
//jab koi closing bracket ayega,we will check jo waiting state mein abhi last added 
//bracket hai,agar uska closing counter part hogi,toh usse waiting mein se bhar nikal
//denge...isse tarah after traversing the whole string,if waiting state gets empty,
//our bracket is balanced.

//closing bracket lastly added bracket ka hi counter closing part hona chaihiye.
//({)}.in this case,since first closing bracket is not the counter closing part of
//lastly added bracket in waiting state,it is not a balanced bracket.


//waiting state ko hum stack maan lenge and and last added bracket hum top se access kar lenge.
//when we encounter an opening bracket,we push it in stack.
//when we encounter an closing bracket,we checkif stack is not empty,if it is empty,return false.
//if not empty,we check if it is equal to top,if yes, move ahead otherwise,return false.
//isse tarah after traversing the whole bracket,if stack gets empty,
//our bracket is balanced.hence return true.

//when you have all type of brackets in the input..
#include<iostream>    //space complexity-o(n)   time complexity-o(n)
#include<stack>
using namespace std;
bool is_balanced(string bracket){
    stack<char> st;
    int length=bracket.size();
    for(int i=0;i<length;i++){
        char ch=bracket[i];
        if(ch=='{'|| ch=='('|| ch=='['){
            st.push(ch);
        }
        else{
            if(st.empty()){
                return false;
            }
            else{
             if(ch==')' && st.top()=='('){
                st.pop();
             }
             else if(ch=='}' && st.top()=='{'){
                st.pop();
             }
             else if(ch==']' && st.top()=='['){
                st.pop();
             }
             else{
                return false;
             }
            
            }
        }
    }
    return st.empty();
}
int main(){
    string bracket;
    cin>>bracket;

    cout<<is_balanced(bracket);
}

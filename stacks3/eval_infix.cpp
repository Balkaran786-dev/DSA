/*approach:
  we will maintain two stacks,1st for numbers and 2nd for operators.
  whenever,we approach a number,push it in stack1.
  whenever,we have a operator,if it is the first operator,push it normally in stack 2.
  if not,check that its precedence should be greater than or equal to previously added opeartor.
  if yes,push it normally.Otherwise,we solve the numbers with the corresponding operators,
  till,either stack gets empty or the precedence of top operator is less than the curr operator.
  
  if we approach a '(' bracket,push it normally,but if we approach ')',evaluate till we get '(' on 
  top of stack 2.then pop out '(' also from stack.
*/


#include<iostream>
#include<string>
#include<stack>
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
    else if(ch=='%'){
        return v1%v2;
    }
    else{
        return v1-v2;
    }
}
int precedence(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/' || ch=='%') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return -1;
}
int eval(string str){
    stack<int> nums;
    stack<char> ops;
    for(int i=0; i<str.size(); i++){
        char ch=str[i];
        if(isdigit(ch)){
            nums.push(ch-'0');
        }
        else if(ch=='('){
            ops.push(ch);
        }
        else if(ch==')'){
            while(ops.top()!='('){
                char op=ops.top();
                ops.pop();

                int v2=nums.top();
                nums.pop();
                int v1=nums.top();
                nums.pop();
                nums.push(calu(v1,v2,op));
            }
            ops.pop();   //poping out '('.
        }
        else{
            while(!ops.empty() && precedence(ops.top())>precedence(ch)){  
                char op=ops.top();
                ops.pop();

                int v2=nums.top();
                nums.pop();
                int v1=nums.top();
                nums.pop();
                nums.push(calu(v1,v2,op));
            }
            ops.push(ch);
        }

    }
    while(!ops.empty()){
        char op=ops.top();
        ops.pop();

        int v2=nums.top();
        nums.pop();
        int v1=nums.top();
        nums.pop();
        nums.push(calu(v1,v2,op));
    }

    return nums.top();
}
int main(){
    string str="1+(2*(3-1))+2";
    cout<<eval(str);
    return 0;
}


//code written while revision

// #include<bits/stdc++.h>
// using namespace std;
// int calc(int v1,int v2,char ch){
//     if(ch=='^'){
//         return pow(v1,v2);
//     }
//     else if(ch=='+'){
//         return v1+v2;
//     }
//     else if(ch=='-'){
//         return v1-v2;
//     }
//     else if(ch=='*'){
//         return v1*v2;
//     }
//     else{
//         return v1/v2;
//     }
// }
// int prec(char ch){
//     if(ch=='^') return 3;
//     else if(ch=='/' || ch=='*') return 2;
//     else if(ch=='-' || ch=='+') return 1;
//     else return -1;
// }
// int infix_eval(string &str){
//     stack<int> num;
//     stack<char> ops;
//     for(int i=0;i<str.size();i++){
//         char curr=str[i];
//         if(isdigit(curr)){
//             num.push(curr -'0');
//         }
//         else{
//             if(curr=='(') ops.push(curr);
//             else if(curr==')'){
//                 while(ops.top()!='('){
//                     char opr=ops.top();
//                     ops.pop();
//                     int v2=num.top();
//                     num.pop();
//                     int v1=num.top();
//                     num.pop();
//                     int solu=calc(v1,v2,opr);
//                     num.push(solu);
//                 }
//                 ops.pop();  //poping out the opening bracket;
//             }
//             else{
//                 while(prec(ops.top())>prec(curr) && !ops.empty()){
//                     char opr=ops.top();
//                     ops.pop();
//                     int v2=num.top();
//                     num.pop();
//                     int v1=num.top();
//                     num.pop();
//                     int solu=calc(v1,v2,opr);
//                     num.push(solu);
//                 }
//                 ops.push(curr);
//             }
//         }
//     }
//     while(!ops.empty()){
//         char opr=ops.top();
//         ops.pop();

//         int v2=num.top();
//         num.pop();
//         int v1=num.top();
//         num.pop();
//         int solu=calc(v1,v2,opr);
//         num.push(solu);
//     }
//     return num.top();
// }
// int main(){
//     string str="1+(2*(3-1))+2";
//     cout<<infix_eval(str);
//     return 0;
// }




//to handle more than 2 digit numbers
#include <iostream>
#include <string>
#include <stack>
#include <cmath>  // for pow
using namespace std;

int calu(int v1, int v2, char ch) {
    if (ch == '^') return pow(v1, v2);
    else if (ch == '+') return v1 + v2;
    else if (ch == '*') return v1 * v2;
    else if (ch == '/') return v1 / v2;
    else if (ch == '%') return v1 % v2;
    else return v1 - v2;  // for '-'
}

int precedence(char ch) {
    if (ch == '^') return 3;
    else if (ch == '*' || ch == '/' || ch == '%') return 2;
    else if (ch == '+' || ch == '-') return 1;
    else return -1;
}

int eval(string str) {
    stack<int> nums;
    stack<char> ops;

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];

        // If digit found, read full number
        if (isdigit(ch)) {
            int num = 0;
            while (i < str.size() && isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            nums.push(num);
            i--; // Adjust because for loop will increment i
        }
        else if (ch == '(') {
            ops.push(ch);
        }
        else if (ch == ')') {
            while (ops.top() != '(') {
                char op = ops.top(); ops.pop();
                int v2 = nums.top(); nums.pop();
                int v1 = nums.top(); nums.pop();
                nums.push(calu(v1, v2, op));
            }
            ops.pop(); // remove '('
        }
        else if (ch == ' ') {
            continue; // skip spaces
        }
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(ch)) {
                char op = ops.top(); ops.pop();
                int v2 = nums.top(); nums.pop();
                int v1 = nums.top(); nums.pop();
                nums.push(calu(v1, v2, op));
            }
            ops.push(ch);
        }
    }

    while (!ops.empty()) {
        char op = ops.top(); ops.pop();
        int v2 = nums.top(); nums.pop();
        int v1 = nums.top(); nums.pop();
        nums.push(calu(v1, v2, op));
    }

    return nums.top();
}

int main() {
    string str = "10+(25*(3-1))+245";
    cout << eval(str);
    return 0;
}

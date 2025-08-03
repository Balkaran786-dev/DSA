// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;
// void f(string s,int idx,string result,vector<string> &li){
//     if(idx==s.length()){
//         li.push_back(result);
//         return;
//     }
//     f(s,idx+1,result+s[idx],li);
//     f(s,idx+1,result,li);
// }
// int main(){
//     string s="abcd";
//     string result="";
//     vector<string> li;
//     f(s,0,result,li);
//     for(int i=0;i<li.size();i++){
//         cout<<li[i]<<" ";
//     }
//     return 0;
// }

// #include<iostream>
// #include<vector>
// using namespace std;
// void f(string str,int idx,int n,string result,vector<string> &li,vector<string> v){
//     if(idx==n){
//         li.push_back(result);
//         return;
//     }
//     int digit=str[idx]-'0';
//     if(digit<=0) f(str,idx+1,n,result,li,v);
//     for(int j=0;j<v[digit].size();j++){
//         f(str,idx+1,n,result+v[digit][j],li,v);
//     }
// }
// int main(){
//     string str="23";
//     vector<string> v(10);
//     v={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//     vector<string> li;
//     string result="";
//     f(str,0,2,result,li,v);
//     for(int i=0;i<li.size();i++){
//         cout<<li[i]<<" ";
//     }
//     return 0;
// }



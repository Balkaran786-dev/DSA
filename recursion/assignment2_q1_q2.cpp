// #include<iostream>
// #include<string>
// using namespace std;
// void f(string &str,int idx,char &ch,string &ans){
//     if(idx>=str.length()) return;
    
//     if(str[idx]==ch){
//         f(str,idx+1,ch,ans);
//     }
//     else{
//         ch=str[idx];
//         ans.push_back(str[idx]);
//         f(str,idx+1,ch,ans);
//     }
// }
// int main(){
//     string str="aabbmnhhgcccdddd";
//     string ans="";
//     char ch=' ';
//     f(str,0,ch,ans);
//     cout<<ans;
//     return 0;
// }



#include<iostream>
#include<string>
using namespace std;
void f(string &str,int idx){
    if(idx>=str.length()) return;
    
    f(str,idx+1);
    cout<<str[idx];
}
int main(){
    string str="Balkaran";
    f(str,0);
    return 0;
}



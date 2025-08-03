#include<iostream>
#include<string>
using namespace std;
bool is_palindrome(string &str){
    int idx1=0;
    int idx2=str.size()-1;
    while(idx1<=idx2){
        if(str[idx1]!=str[idx2]){
            return false;
        }
        idx1++;
        idx2--;
    }
    return true;
}
bool is_rotated_palindrome(string &str){
    int idx1=0;
    int idx2=str.length();
    str+=str; 
    string temp;
    while(idx2!=str.length()){
         temp=str.substr(idx1,idx2-idx1+1);
         bool res=is_palindrome(temp);
         if(res==true) return true;
         idx1++;
         idx2++;
    }
    return false;
}
int main(){
    string str;
    cin>>str;
    cout<<is_rotated_palindrome(str);
    return 0;
}
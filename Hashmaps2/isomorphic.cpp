#include<iostream>
#include<unordered_map>
using namespace std;
bool is_isomorphic(string str1,string str2){
       unordered_map<char,char> mapping;
       for(int i=0;i<str1.size();i++){
        char ch1=str1[i];
        char ch2=str2[i];
        if(mapping.find(ch1)!=mapping.end()){
            if(mapping[ch1]!=ch2){
                return false;
            }
        }
        else{
            mapping[ch1]=ch2;
        }
       }

       return true;
}
bool check_if_isomorphic(string str1,string str2){

    if(str1.size()!=str2.size()){
        return false;
    }

    bool s1ands2=is_isomorphic(str1,str2);
    bool s2ands1=is_isomorphic(str2,str1);

    return s1ands2 && s2ands1;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;

    cout<<(check_if_isomorphic(s1,s2)?"ISOMORPHIC":"NOT ISOMORPHIC");
    return 0;
}
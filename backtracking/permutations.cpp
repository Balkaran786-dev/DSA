#include<iostream>
#include<vector>
using namespace std;

void f(string &s,int i,vector<string> &v){
    if(i==s.size()){
        v.push_back(s);
        return;
    }
    for(int j=i;j<s.size();j++){
        char ch1=s[i];
        s[i]=s[j];
        s[j]=ch1;

        f(s,i+1,v);

        char ch2=s[i];
        s[i]=s[j];
        s[j]=ch2;
    }
}
int main(){
    string s="abcd";
    vector<string> v;
    f(s,0,v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}

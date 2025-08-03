#include<iostream>
#include<vector>
using namespace std;
bool is_isomporphic(string s1,string s2){
     vector<int> v1(26,-1);
     vector<int> v2(26,-1);

     if(s1.size()!=s2.size()){  //if size does not matches.
        return false;
     }
     for(int i=0;i<s1.size();i++){
        if(v1[s1[i]-'a']!=v2[s2[i]-'a']){
            return false;
        }
        else{
            v1[s1[i]-'a']=v2[s2[i]-'a']=i;
        }
     }
     return true;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<is_isomporphic(s1,s2);
    return 0;
}
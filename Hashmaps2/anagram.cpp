#include<iostream>
#include<unordered_map>
using namespace std;
bool is_anagram(string s1,string s2){

    if(s1.size()!=s2.size()){
        return false;
    }

    unordered_map<char,int> freq;
    for(auto ch:s1){
        freq[ch]++;
    }

    for(auto ch:s2){
        if(freq.find(ch)==freq.end()){
            return false;
        }
        
        freq[ch]--;
    }

    for(auto ele:freq){
        if(ele.second!=0){
            return false;
        }
    }

    return true;

}
int main(){
    string s1,s2;
    cin>>s1>>s2;

    cout<<(is_anagram(s1,s2)?"ANAGRAM":"NOT AN ANAGRAM");
    return 0;
}
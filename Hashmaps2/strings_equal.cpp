#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool is_equal(vector<string> &v){

    unordered_map<char,int> freq;  //to store frequency of every unique character.
    for(auto ele:v){    // for getting ele from vector. 
        for(char ch:ele){   //for getting every character from each ele.
            freq[ch]++;   
        }
    }

    int n=v.size();
    for(auto ele:freq){  
        if(ele.second % n!=0){   //freq of every character should be the multiple of n.
            return false;       
        }
    }

    return true;
}
int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<(is_equal(v)?"YES ":"No");
    return 0;
}
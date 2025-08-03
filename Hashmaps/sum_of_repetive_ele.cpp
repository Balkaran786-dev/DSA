#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    /*  //in this way,it happens.
    m[1]++; --> {{1,1}}
    m[1]++; --> {{1,2}}
    m[3]++; --> {{3,1}}
    */
    map<int,int> m;
    for(auto ele:v){
        m[ele]++;
    }

    int sum=0;
    for(auto ele:m){
       if(ele.second>1){
        sum+=ele.first;
       }
    }

    cout<<"ANS:"<<sum;
    return 0;
}
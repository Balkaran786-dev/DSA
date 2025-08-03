#include<bits/stdc++.h>
using namespace std;
int fact(int x){
    if(x==1 || x==0){
        return 1;
    }
    
    return x*fact(x-1);
}
int nCr(int n,int r){
    return fact(n)/(fact(r)*fact(n-r));
}
int main(){
    int numRows;
    cin>>numRows;

    vector<vector<int>> ans(numRows);
    
    for(int i=0;i<numRows;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || i==j){
             ans[i].push_back(1);
            }
            else{
             ans[i].push_back(nCr(i,j));
            }    
        }
    }
    
    for(int i=0;i<numRows;i++){
        for(auto ele:ans[i]){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    return 0;
}
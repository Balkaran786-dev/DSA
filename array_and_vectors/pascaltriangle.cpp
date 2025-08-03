/*#include<iostream>
#include<vector>
using namespace std;
int fact(int num){
    int factorial=1;
    if(num==0){
        return 1;
    }
    while(num!=0){
        factorial*=num;
        num--;
    }
    return factorial;
}
int nCr(int n,int r){
    return fact(n)/(fact(r)*fact(n-r));
}
int main(){
    int n;
    cin>>n;

    vector<vector<int>> vec(n,vector<int>(n));
  
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
           vec[i][j]=nCr(i,j);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//2nd approach

int main(){
    int n;
    cin>>n;
    vector<vector<int>> vec(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || i==j){
               vec[i][j]=1;
            }
            else{
                vec[i][j]=vec[i-1][j]+vec[i-1][j-1];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}*/
   

   //more accurate way to do this.

#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> pascalTriangle(int n){
     vector<vector<int>> pascal(n);  // initialise a 2d vector of n vectors

     for(int i=0;i<n;i++){
        pascal[i].resize(i+1);  //pascal[i] is basically the ithvector of pascal 2d vector
        for(int j=0;j<=i;j++){
            if(j==0 || i==j){
                pascal[i][j]=1;
            }
            else{
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
            }
        }
     }
     return pascal;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> ans;
    ans=pascalTriangle(n);

    for(int i=0;i<ans.size();i++){  // ans is a 2d vector and ans.size() gives the number of vectors present in it
        for(int j=0;j<ans[i].size();j++){  // ans[i] is the ith vector in 2d vector ans... ans[i].size() gives size of that ith vector
        cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
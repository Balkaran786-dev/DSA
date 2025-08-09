#include<bits/stdc++.h>
using namespace std;
int cnt_word(string s,string test){
    int n=s.size();
    int i=0;
    int cnt=0;
    while(i<n){
        if(s[i]==' '){
            i++;
            continue;
        }
        int start=i;
        while(i<n && s[i]!=' '){
            i++;
        }
        string str=s.substr(start,i-start);
        if(str==test) cnt++;
    }
    return cnt;
}
int cnt_substring(string s,string test){
    int n=s.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(s.substr(i,j-i+1)==test) cnt++;
        }
    }
    return cnt;
}

int cnt_subsequence(string &s,string &test,int i,int j,vector<vector<int>> &dp){
    if(j==test.size()) return 1;
    if(i==s.size()) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans=0;
    ans+=cnt_subsequence(s,test,i+1,j,dp);
    if(s[i]==test[j]){
        ans+=cnt_subsequence(s,test,i+1,j+1,dp);
    }
    return dp[i][j]=ans;
}

int main(){
   string sen;
    getline(cin, sen); 

    string word, substring, subsequence;
    cin >> word;
    cin.ignore();               
    getline(cin, substring);   
    cin >> subsequence;

    cout << cnt_word(sen, word) << endl;
    cout << cnt_substring(sen, substring) << endl;
   
   vector<vector<int>> dp(sen.size(),vector<int> (subsequence.size(),-1));
   cout<<cnt_subsequence(sen,subsequence,0,0,dp);
}
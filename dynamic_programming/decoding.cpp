// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;
// vector<int> dp;///=global vector
// int string_to_int(string str){
//     if(str.size()==1) return str[0]-'0';
//     return (str[0]-'0')*10 + (str[1]-'0');
// }
// int f(string str,int idx){
//     if(str[idx]=='0' || idx>=str.size()) return 0;

//     if(idx==str.size()-1){   //if the size of the string remains only one
//         if(str[idx]=='0') return 0;
//         else return 1;
//     }

//     if(idx==str.size()-2){   //for 2 sized string
//         bool can_form_2_digits=string_to_int(str.substr(idx,2))<=26;
//         return can_form_2_digits+f(str,idx+1);
//     }
    
//     if(dp[idx]!=-1){
//         return dp[idx];
//     }
//        bool can_form_2_digits=string_to_int(str.substr(idx,2))<=26;
//        return dp[idx]=f(str,idx+1)+(can_form_2_digits? f(str,idx+2):0);

// }
// int main(){
//     string str="1130";
//     dp.resize(str.size()+100,-1);
//     cout<<f(str,0);
//     return 0;
//  }




#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> dp;///=global vector
int string_to_int(string str){
    if(str.size()==1) return str[0]-'0';
    return (str[0]-'0')*10 + (str[1]-'0');
}
int f(string str){
     int n=str.size();
     dp[n-1]=(str[n-1]=='0'? 0:1);
     if(str[n-2]=='0'){
        dp[n-2] = 0;
     }
     else{
        bool can_form_2_digits = string_to_int(str.substr(n-2,2))<=26;
        dp[n-2]= can_form_2_digits + dp[n-1];
     }

     for(int i=n-3;i>=0;i--){
        if(str[i]=='0'){
            dp[i]=0;
        }
        else{
             bool can_form_2_digits = string_to_int(str.substr(i,2))<=26;
             dp[i]=dp[i+1]+(can_form_2_digits ? dp[i+2]:0);
        }
     }

     return dp[0];
}
int main(){
    string str="2256";
    dp.resize(str.size());
    cout<<f(str);
    return 0;
}



class Solution {
public:
    vector<int> dp;
    int decode(string &s,int idx,int n){
        if(idx==n) return 0;

        if(s[idx]=='0') return 0;

        if(idx==n-1){
            return (s[idx]=='0'? 0 : 1);
        }

        if(idx==n-2){
            int value=stoi(s.substr(idx,2));
            return decode(s,idx+1,n)+((value>=1 && value<=26)? 1: 0);
        }

        if(dp[idx]!=-1) return dp[idx];
        
        int val=decode(s,idx+1,n);
        int value=stoi(s.substr(idx,2));
        if(value>=1 && value<=26){
            val+=decode(s,idx+2,n);
        }
        
        return dp[idx]=val; 
    }

    int fbu(string &s,int n){
         
         dp[n-1]=(s[n-1]=='0'?0:1);
         int value=stoi(s.substr(n-2,2));
         if(s[n-2]=='0') dp[n-2]=0;
         else dp[n-2]=dp[n-1]+((value>=1 && value<=26)? 1: 0);

         for(int i=n-3;i>=0;i--){
            if(s[i]=='0') dp[i]=0;
            else{
                int value=stoi(s.substr(i,2));
                dp[i]=dp[i+1]+((value>=1 && value<=26)? dp[i+2]: 0);
            }
         }
         return dp[0];
    }
    int numDecodings(string s) {
        
        int idx=0;
        int n=s.size();
        dp.resize(n,-1);
        // int cnt=decode(s,idx,n);
        if(n==1){
            if(s[0]=='0') return 0;
            else return 1;
        }
        return fbu(s,n);
    }
};
// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;
// void count_sort(char s[]){
//     int n=strlen(s);           //time complexity-o(4n+max)  space complexity-o(max+n)
//     int max_ele=INT16_MIN;
//     for(int i=0;i<n;i++){
//        max_ele=max(max_ele,int(s[i]));
//     }
//     vector<int> freq(max_ele+1,0);
//     for(int i=0;i<n;i++){
//          freq[int(s[i])]++;
//     }
//     for(int i=1;i<freq.size();i++){
//         freq[i]+=freq[i-1];
//     }
//     char ans[n];
//     for(int i=n-1;i>=0;i--){
//         ans[--freq[int(s[i])]]=s[i];
//     }
//     for(int i=0;i<n;i++){
//         s[i]=ans[i];
//     }
// } 
// int main(){
//     char s[20];
//     cin>>s;
//     count_sort(s);
//     cout<<s;
//     return 0;
// }

//a more optimised approach is given below;
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string sort(string &str){    //our string just contain characters from a to z.
     vector<int> freq(26,0);
     for(int i=0;i<str.size();i++){
        int index=str[i]-'a';
        freq[index]++;
     }
     int j=0;
     for(int i=0;i<26;i++){
        while(freq[i]){
            str[j++]=i+'a';
            freq[i]--;
        }
     }
     return str;
}
int main(){
    string str;
    cin>>str;
    cout<<sort(str);
}



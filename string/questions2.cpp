// //checking if one string is anagram of other or not.  (anagram-means one word is made from another by just rearranging the alphabets)
// #include<iostream>  //time complexity-o(len of string)  space complexity-o(26)~~constant
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;
// bool check_anagram(string s1,string s2){
//     if(s1.size()!=s2.size()){   //if length of s1 and s2 comes out to be different,it can't be an anagram
//         return false;
//     }
//     else{
    // making a freq array of 26 size
//     vector<int> freq(26,0);
//     for(int i=0;i<s1.size();i++){ 
//         freq[s1[i]-'a']++;  //for s1,we are incrementing freq of character
//         freq[s2[i]-'a']--;  //for s2,we are decrementing freq of character
//     }

//    //checking if freq of every character is zero
//     for(int i=0;i<26;i++){
//         if(freq[i]!=0){
//             return false;
//         }
//     }
//     }
//     return true;
// }
// int main(){
//     string s1;
//     string s2;
//     cin>>s1>>s2;
//     cout<<check_anagram(s1,s2);
//     return 0;
// }
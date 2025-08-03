////1st approach     time complexity-o(n^2)  space complexity-o(1)
// #include<iostream>
// #include<algorithm>
// #include<bits/stdc++.h>
// using namespace std;
// int max_len(string str,int max_zeroes){
//      int length=INT16_MIN;
//      string s;
//      for(int i=0;i<str.size();i++){
//         int no_of_zeroes=0;
//         for(int j=i;j<str.size();j++){

//             if(str[j]=='0') no_of_zeroes+=1;

//             if(no_of_zeroes<=max_zeroes){
//                 length=max(length,j-i+1);
//             }
//             else{
//                 break;
//             }
//         }
//      }
//      return length;
// }
// int main(){
//     string input;  //binary string
//     cin>>input;
//     int k;
//     cin>>k;
//     cout<<max_len(input,k);
//     return 0;
// }



#include<iostream>   //time complexity-o(n)  space complexity-o(1);
#include<bits/stdc++.h>
using namespace std;
int main(){
    string input;
    cin>>input;
    int k;
    cin>>k;
    int s=0,e=0,zero_count=0;
    int max_length=0;
    while(e<input.size()){
        if(input[e]=='0'){
            zero_count+=1;
        }
        //contracting our window when condition is wrong
        while(zero_count>k){
            if(input[s]=='0') zero_count--;  //kyunki kai baar hum 1 bhi pass
                                             //kar skte hain,in that case,we don't need to decrement our zero count.
            s++;
        }   

        max_length=max(max_length,e-s+1); //updating our max_length
        e+=1;  //expanding our window when condition becomes right.
    }
    cout<<max_length;
    return 0;
}




   //time complexity-o(n)  space complexity-o(1);
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     string str;
//     int k;
//     cin>>str;
//     cin>>k;
//     int count_of_zero=0,total_count=0;
//     int max_count=INT16_MIN;
    
//     for(int i=0;i<n.size();i++){
//         if(str[e]=='0'){
//             count_of_zero++;
//         }
        
//         if(count_of_zero<=k){
//             total_count++;
//             max_count=max(max_count,total_count);
//         }
//         else{
//             while()
//         }
//     }
//     return 0;
// }
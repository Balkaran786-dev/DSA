// #include<iostream>
// using namespace std;
// void f(string &s,int idx,int length,char ch,string &ans){
//     if(idx==length){
//         return;
//     }
// // hum akela s[idx] sedha nhi add kar sakte because it is considered as a character only and we
//                   //we can add string to string but not character to string,hence we did this thing.
//     if(s[idx]!=ch){
//          ans.push_back(s[idx]);
//     }
//     f(s,idx+1,length,ch,ans);
// }
// int main(){
//     string s="abacda";
//     string ans="";
//     f(s,0,6,'a',ans);
//     cout<<ans;
// }

// //checking palindrome using string.
// #include<iostream>
// using namespace std;
// int f(string &s,int left_idx,int right_idx){
//     if(left_idx>=right_idx){  //equal in case of of odd charcters and left>right in case of even characters.
//         return 1;
//     }
//     else{
//     if(s[left_idx]!=s[right_idx]){
//         return 0;
//     }
//     else{
//         f(s,left_idx+1,right_idx-1);
//     }
//     }
// }
// int main(){
//     string s="abcdba";
//     int result=f(s,0,4);
//     cout<<result;
//     return 0;
// }

// #include<iostream>
// using namespace std;// yahan agr humme pehli baar hi pata chl gya ki palindrome nhi hai tabh bhi sara check karna pdega.
//                     //unlike the previous one where you get out of function when you get to know that it is non-palindrome
// bool f(string &s,int left_idx,int right_idx){
//     if( left_idx>=right_idx){
//         return s[left_idx]==s[right_idx];
//     }
//     return (s[left_idx]==s[right_idx]) && f(s,left_idx+1,right_idx-1);
// }
// int main(){
//     string s="adcba";
//     int result=f(s,0,4);
//     cout<<result;
//     return 0;
// }

//checking a number is palindrome without using string.
// #include<iostream>
// using namespace std;
// bool f(int num,int *temp){
//     if(num>=0 && num<=9){
//         int lastdigitoftemp=(*temp)%10;
//         *temp/=10;
//         return (num==lastdigitoftemp);
//     }
//     bool result=f(num/10,temp)&&(num%10==(*temp)%10);
//     (*temp)/=10;
//     return result;
// }
// int main(){
//     int num;
//     cin>>num;
//     cout<<f(num,&num);
// }

// #include<iostream>
// using namespace std;
// bool f(int num,int *temp){
//     if(num>=0 && num<=9){
//        int last_digit_of_temp=(*temp)%10;
//         *temp/=10;
//         return (num==last_digit_of_temp);
//     }
//     bool result=f(num/10,temp) && (num%10==*temp%10);
//     *temp/=10;
//     return result;
// }
// int main(){
//     int num;
//     cin>>num;
//     cout<<f(num,&num);
//     return 0;
// }
// #include<iostream>
// using namespace std;
// bool f(int temp,int &num){
//     if(temp>=0 && temp<=9){
//         int last_dig=num%10;
//         num/=10;
//         return last_dig==temp;
//     }
    
//     bool res=f(temp/10,num);
//     if(res==false) return false;
//     else{
//         int last_dig=num%10;
//         num/=10;
//         return last_dig==temp%10;
//     }
// }
// int main(){
//     int x=123211;
//     cout<<f(x,x);
//     return 0;
// }
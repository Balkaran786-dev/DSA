#include<bits/stdc++.h>
using namespace std;
 int get_set_bits(int num){
       int parity;
       int set_bits=0;
       while(num>0){
        parity=num%2;
        if(parity==1) set_bits++;
        num/=2;
       }
       
    //    while( binary_number!=0){
    //     int parity= binary_number%10;
    //      binary_number/=10;
    //     if(parity==1) set_bits++;
    //    }
       return set_bits;
    
    }
int main(){
    cout<<get_set_bits(15);
    // int decimal_Number;
    // cout<<"Enter the decimal Number: ";
    // cin>>decimal_Number;

    // int binary_number=0,parity,power=1;
    // while(decimal_Number>0){
    //     parity=decimal_Number%2;
    //     binary_number+=parity*power;
    //     power*=10;
    //     decimal_Number/=2;
    // }

    // cout<<binary_number<<endl;

    // string num=to_string(binary_number);
    // int max_dis=INT16_MIN;
    // int prev=0;
    // for(int i=1;i<num.size();i++){
    //     if(num[i]=='1'){
    //         max_dis=max(max_dis,i-prev-1);
    //         prev=i;
    //     }
    // }
    
    // cout<<max_dis;
    // return 0;
}

// #include<iostream>
// using namespace std;
// class Solution {
// public:
//    int convert_to_bin(int &decimal_Number){
//     int binary_number=0,parity,power=1;
//     while(decimal_Number>0){
//         parity=decimal_Number%2;
//         binary_number+=parity*power;
//         power*=10;
//         decimal_Number/=2;
//     }
//     return binary_number;
//    }
    
//     int hammingWeight(long long int n) {
//         int bin_num=convert_to_bin(n);
//         int count=0;
//         int parity;
//         while(bin_num!=0){
//             parity=bin_num%10;
//             if(parity==1) count++;
//             bin_num/=10;
//         }
//         return count;
//     }
// };

// int main(){
//     Solution s;
//     cout<<s.hammingWeight(2147483645);
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     void get_permutations(vector<int>& nums,int i,vector<vector<int>>&ans){
//         if(i==nums.size()){
//             ans.push_back(nums);
//             return;
//         }

//         for(int j=i;j<nums.size();j++){
//             swap(nums[i],nums[j]);
//             get_permutations(nums,i+1,ans);
//             swap(nums[i],nums[j]);
//         }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         get_permutations(nums,0,ans);
//         return ans;
//     }
// };

// int main(){
//     Solution s;
//     vector<int> v={1,2,3};
//     vector<vector<int>> ans=s.permute(v);
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<ans[i].size();j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }
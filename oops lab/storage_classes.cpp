// // #include<bits/stdc++.h>
// // using namespace std;
// // //these variables i'll be making extern variables
// // extern int x;
// // void extern_storage_class(){
// //      cout<<x<<endl;
// //      x=90;
// //      cout<<x;
// // }
// // int static_storage_class(){
// //     static int a=1;
// //     a++;
// //     return a;
// // }
// // int register_storage_class(){
// //     register int a=1;
// //     a++;
// //     return a;
// // }
// // int x=0;
// // int main(){
// //     cout<<"Static storage class:- "<<endl;
// //     cout<<static_storage_class()<<endl;
// //     cout<<static_storage_class()<<endl;
// //     cout<<static_storage_class()<<endl;

// //     cout<<"Register storage class:- "<<endl;
// //     cout<<register_storage_class()<<endl;
// //     cout<<register_storage_class()<<endl;
// //     cout<<register_storage_class()<<endl;
    
// //     cout<<"Extern storage class:- "<<endl;
// //     extern_storage_class();
// // }

// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int count=1;
//         int i=0;
//         for(int j=1;j<nums.size();j++){
//             switch (count){
//                 case 1:
//                  if(nums[i]==nums[j]){
//                     i++;
//                     nums[i]=nums[j];
//                     count=2;
//                  }
//                  else{
//                     i++;
//                     nums[i]=nums[j];
//                  }
//                  break;
//                 case 2:
//                  if(nums[i]!=nums[j]){
//                     i++;
//                     nums[i]=nums[j];
//                     count=1;
//                  }
//                  break;
//                 default:
//                  cout<<"nothing";
//                  break;
//             }
//         }
//         return i+1;
//     }
// };
// int main(){
//     // Solution s;
//     // vector<int> v={0,1,1,1,2,2,3,4};
//     // cout<<s.removeDuplicates(v);

//     double a=pow(2.1000,3);
//     cout<<a;

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
unordered_set<vector<int>> st;
class Solution {
public:
     //it stores the required possible unique permutations.
    void get_permute(vector<int>& nums,int i,vector<vector<int>> &ans){
        if(i==nums.size()){
            if(st.count(nums)){
                return;
            }
            st.insert(nums);
            ans.push_back(nums);
            return;
        }

        for(int j=i;j<nums.size();j++){
                swap(nums[i],nums[j]);
                get_permute(nums,i+1,ans);
                swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        get_permute(nums,0,ans);
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> v={1,1,2};
    vector<vector<int>> ans=s.permuteUnique(v);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
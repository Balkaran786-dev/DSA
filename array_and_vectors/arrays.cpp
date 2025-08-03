#include<bits/stdc++.h>

using namespace std;
// int main(){
// //     int array[]={2,4,6,8};

// //    cout<<sizeof(array)<<endl;
// //     cout<<"Length of array:"<<sizeof(array)/sizeof(array[0])<<endl;

// //     //printing every elements of array.

// //     int size=sizeof(array)/sizeof(array[0]);

// //     //for loop.
// //     for(int idx=0;idx<size;idx++){
// //         cout<<array[idx]<<endl;
// //     }

// //     //for each loop.
// //     for(int ele:array){
// //         cout<<ele<<endl;  //it will print every element we dont have a choice to print only some desired elements here.. 
// //     }

// //     //while loop.
// //     int idx=0;
// //     while(idx<size){
// //         cout<<array[idx]<<endl;
// //         idx++;
// //     }

// //     char vowels[5];
// //     for(int idx=0;idx<5;idx++){
// //         cin>>vowels[idx];
// //     }

// //     for(char &element:vowels){  //we use ampersand operator so the values given to elements gets directly transferred to array..
// //         cin>>element;
// //     }
// //     for(int idx=0;idx<5;idx++){
// //         cout<<vowels[idx]<<" ";
// //     }
class Solution {
public:
    
    int findKthLargest(vector<int>& nums, int k) {
        int first_larg=INT_MIN;
        int second_larg=INT_MIN;
        if(k==1){
            for(int i=0;i<nums.size();i++){
                first_larg=max(first_larg,nums[i]);
            }
            return first_larg;
        }
        int i=0;
        while(i!=k-1){
            for(int j=0;j<nums.size();j++){
                if(nums[j]>=first_larg){
                    second_larg=first_larg;
                    first_larg=nums[j];
                }
                else if(nums[j]>=second_larg) second_larg=nums[j];
            }

            cout<<first_larg<<" "<<second_larg<<endl;
            if(i==0){
                auto it1=find(nums.begin(),nums.end(),first_larg);
                if(it1!=nums.end()) nums.erase(it1);
            }
            
            auto it2=find(nums.begin(),nums.end(),second_larg);
            if(it2!=nums.end()) nums.erase(it2);
            for(int i=0;i<nums.size();i++){
                cout<<nums[i]<<" ";
            }
            cout<<endl;
            
            first_larg=second_larg;
            
            second_larg=INT_MIN;
            i++;
        }
        return first_larg;
    }
};
int main(){
    vector<int> n={3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    Solution s;
    cout<<s.findKthLargest(n,20);
}
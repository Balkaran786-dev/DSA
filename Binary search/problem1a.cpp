// #include<iostream>
// #include<vector>
// using namespace std;
// int firstoccurrence(vector<int> v,int target){
//     int lo=0; //starting of the array
//     int hi=v.size()-1; //ending of the array
//     int ans=-1;
//     while(lo<=hi){
//         int mid=(lo+hi)/2;  //modified form to tackle overflow mid=lo+(hi-lo)/2
//         if(v[mid]==target){
//             ans=mid;
//             hi=mid-1;
//         }
//         else if(v[mid]>target){
//             hi=mid-1;
//         }
//         else{
//             lo=mid+1;
//         }
//     }
//     return ans;

// }
// int lastoccurrence(vector<int> v,int target){
//     int lo=0;
//     int hi=v.size()-1;
//     int ans=-1;
//     while(lo<=hi){
//         int mid=(hi+lo)/2;
//         if(v[mid]==target){
//             ans=mid;
//             lo=mid+1;
//         }
//         else if(v[mid]>target){
//             hi=mid-1;
//         }
//         else{
//             lo=mid+1;
//         }
//     }
//     return ans;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> v(n);
//     for(int &ele:v){
//       cin>>ele;
//     }
//     int target;
//     cout<<"enter the target element:";
//     cin>>target;
//     vector<int> result;
//     int first=firstoccurrence(v,target);
//     if(first==-1){
//        result.push_back(-1);
//        result.push_back(-1);
//     }
//     else{
//         int last=lastoccurrence(v,target);
//         result.push_back(first);
//         result.push_back(last);
//     }
//     for(int i=0;i<result.size();i++){
//         cout<<result[i]<<" ";
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int lower_bound(vector<int> &v,int target){  //lowerbound is ele that is just > or =target and equal to sabse pehle vala...
//         int lo=0;
//         int hi=v.size()-1;
//         int ans=-1;
//         while(lo<=hi){
//             int mid=lo+(hi-lo)/2;
//             if(v[mid]>=target){  //agr brabr bhi hua toh may be uske pehle bhi same element ho and we need ki sabse pehle vali occurence
//                              //and agr target se bada bhi hua may be first half mein target se just greater element present ho,so we will call for first half
//                 ans=mid;
//                 hi=mid-1; 
//             }
//             else{
//                 lo=mid+1; //agr us target se shota hua toh to equal to ya greater than target toh uske next half mein hi milege
//             }
//         }
//         return ans;
// }
// int upper_bound(vector<int> &v,int target){
//     int lo=0;
//     int hi=v.size()-1;
//     int ans=-1;
//     while(lo<=hi){
//         int mid=(hi+lo)/2;
//         if(v[mid]>target){
//             ans=mid;
//             hi=mid-1;
//         }
//         else{
//             lo=mid+1;
//         }
//     }
//     return ans-1;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> v(n);
//     for(int &ele:v){
//       cin>>ele;
//     }
//     int target;
//     cout<<"enter the target element:";
//     cin>>target;
//     vector<int> result;
//     int lb=lower_bound(v,target);
//     if(v[lb]!=target){
//        result.push_back(-1);
//        result.push_back(-1);
//     }
//     else{
//         int ub=upper_bound(v,target);
//         result.push_back(lb);
//         result.push_back(ub);
//     }
//     for(int i=0;i<result.size();i++){
//         cout<<result[i]<<" ";
//     }
//     return 0;
// }


//In rotated sorted array -->duplicates or for non duplicates...
#include<iostream>
using namespace std;
int min_ele_index(int arr[],int lo,int hi){ 
   while(lo<=hi){
    int mid=(hi+lo)/2;
    if(arr[mid]>arr[mid+1]){
        return mid+1;
    }
    else if(arr[mid]<arr[mid-1]){
        return mid;
    }
    else if(arr[mid]>lo){
        lo=mid+1;
    }
    else if(arr[mid]<lo){
        hi=mid-1;
    }
   }
    return -1;
}
int main(){
    int n;
    cout<<"The size is:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<min_ele_index(arr,0,n-1);

    return 0;
}




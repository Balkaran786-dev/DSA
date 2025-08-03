//1st approach
// #include<iostream>
// #include<vector>
// using namespace std;
// int firstocuurence(vector<int> v,int target){
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
//     cout<<firstocuurence(v,target);
//     return 0;
// }

//2nd approach
// #include<iostream>
// using namespace std;
// int firstocuurence(int arr[],int lo,int hi,int target,int ans){
//    if(lo>hi){
//     return ans;
//    }
//    int mid=(lo+hi)/2;
//    if(arr[mid]==target){
//      ans=mid;
//      return firstocuurence(arr,lo,mid-1,target,ans);
//    }
//    else if(arr[mid]>target){
//     return firstocuurence(arr,lo,mid-1,target,ans);
//    }
//    else{
//     return firstocuurence(arr,mid+1,hi,target,ans);
//    }
// }
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int &ele:arr){
//       cin>>ele;
//     }
//     int target;
//     cout<<"enter the target element:";
//     cin>>target;
//     cout<<firstocuurence(arr,0,n-1,target,-1);
//     return 0;
// }


// #include<iostream>
// #include<vector>
// using namespace std;
// int squareroot(int n){
    // int lo=1; //starting of the array
    // int hi=n/2; //ending of the array  //sqaure root of n will always lie between 1 to n/2..
    // int ans;
    // while(lo<=hi){
    //     int mid=(lo+hi)/2;  //modified form to tackle overflow mid=lo+(hi-lo)/2
    //     if(mid*mid<=n){
    //         ans=mid;
    //         lo=mid+1;
    //     }
    //     else{
    //         hi=mid-1;
    //     }
    // }
    // return ans;
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<squareroot(n);
//     return 0;
// }


#include<iostream>
#include<vector>
using namespace std;
int squareroot(int lo,int hi,int ans,int n){
    if(lo>hi){
        return ans;
    }
    int mid=lo+(hi-lo)/2;
    if(mid*mid==n){
        return mid;
    }
    else if(mid*mid<n){
       return squareroot(mid+1,hi,mid,n);
    }
    else{ 
       return squareroot(lo,mid-1,ans,n);
    }
}
int main(){
    int n;
    cin>>n;
    cout<<squareroot(0,n,-1,n);
    return 0;
}



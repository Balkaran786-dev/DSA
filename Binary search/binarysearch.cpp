// #include<iostream>
// #include<vector>
// using namespace std;
// int binarysearch(vector<int> v,int target){
    // int lo=0; //starting of the array
    // int hi=v.size()-1; //ending of the array
    // while(lo<=hi){
    //     int mid=(lo+hi)/2;  //modified form to tackle overflow mid=lo+(hi-lo)/2  
    //                        //to handle the cases when lo and hi becomes very big numbers i.e INT_MAX.
    //     if(v[mid]==target){
    //         return mid;
    //     }
    //     else if(v[mid]>target){
    //         hi=mid-1;
    //     }
    //     else{
    //         lo=mid+1;
    //     }
    // }
    // return -1;
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
//     cout<<binarysearch(v,target);
//     return 0;
// }




#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int> &v,int target,int low,int high){
    if(low>high){
      return -1;
    }
    else{
        int mid=(low+high)/2; //modified form to tackle overflow mid=low+(high-low)/2
        if(v[mid]==target){
            return mid;
        }
        else if(v[mid]>target){
           return binarysearch(v,target,low,mid-1);
        }
        else{
           return binarysearch(v,target,mid+1,high);
        }
    }
}
int main(){
    vector<int> v(7);
    v={13,24,56,47,58,89,90};
    int target;
    cout<<"enter the target element:";
    cin>>target;
    cout<<binarysearch(v,target,0,6);
    return 0;
}

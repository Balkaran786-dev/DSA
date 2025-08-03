// #include<iostream>
// using namespace std;
// int binarysearch(int arr[],int lo,int hi,int target){
//     while(lo<=hi){
//         int mid=(lo+hi)/2;  //modified form to tackle overflow mid=lo+(hi-lo)/2  
//                            //to handle the cases when lo and hi becomes very big numbers i.e INT_MAX.
//         if(arr[mid]==target){
//             return mid;
//         }
//         else if(arr[mid]>target){
//             hi=mid-1;
//         }
//         else{
//             lo=mid+1;
//         }
//     }
//     return -1;
// }
// int min_ele_index(int arr[],int lo,int hi){ 
//     while(lo<=hi){
//         int mid=(hi+lo)/2;
//         if(arr[mid]>arr[mid+1]){
//             return mid+1;
//         }
//         if(arr[mid-1]>arr[mid]){
//             return mid;
//         }
//         if(arr[mid]>arr[lo]){
//              lo=mid+1;
//         }
//         else if(arr[mid]<arr[lo]){
//              hi=mid-1;
//         }
//     }
//     return -1;
// }
// int main(){
//     int n;
//     cout<<"The size is:";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int x;
//     cout<<"The elemet you need to serach:";
//     cin>>x;
//     int min=min_ele_index(arr,0,n-1);
//     int x1=binarysearch(arr,0,min-1,x);
//     int x2=binarysearch(arr,min+1,n-1,x);
//     if(x1!=-1){
//         cout<<x1;
//     }
//     else if(x2!=-1){
//         cout<<x2;
//     }
//     else{
//         cout<<"Not found";
//     }

//     return 0;
// }



#include<iostream>
using namespace std;
int find(int arr[],int lo,int hi,int x){
    while(lo<=hi){
        int mid=(hi+lo)/2;
        if(arr[mid]==x) return mid;
        if(arr[mid]>arr[lo]){
            if(x>=arr[lo] && x<arr[mid]){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        else{
            if(x>arr[mid] && x<arr[hi]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
    }
    return -1;
}
int main(){
    int x;
    cout<<"The element you need to search in the array:";
    cin>>x;
    int arr[]={4,5,6,7,0,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<find(arr,0,n-1,x);

    return 0;
}





// #include<iostream>
// using namespace std;
// int binarysearch(int v[],int lo,int hi,int target){
//     while(lo<=hi){
//         int mid=(lo+hi)/2; 
//         if(v[mid]==target){
//             return 1;
//         }
//         else if(v[mid]>target){
//             hi=mid-1;
//         }
//         else{
//             lo=mid+1;
//         }
//     }
//     return 0;
// }
// int find(int arr[],int lo,int hi,int x){  
//     if(arr[lo]>arr[hi]){   //check if it remains a rotated sorted or not
//     while(lo<=hi){
//         int mid=(hi+lo)/2;
//         if(arr[mid]==x) return 1;
//         if(arr[mid]>=arr[lo]){
//             if(x>=arr[lo] && x<=arr[mid]){
//                 hi=mid-1;
//             }
//             else{
//                 lo=mid+1;
//             }
//         }
//         else{
//             if(x>=arr[mid] && x<=arr[hi]){
//                 lo=mid+1;
//             }
//             else{
//                 hi=mid-1;
//             }
//         }
//     }
//     return 0;
//     } 
//     else{  // if it is not a rotated sorted,apply normal binary search.
//         return binarysearch(arr,lo,hi,x);
//     }
// }
// int remove(int arr[],int l,int r,int x){  //to eliminate the equal element
//     if(arr[l]==x){
//             return 1;
//     } 
//     while(arr[l]==arr[r]){
//         l++;
//         r--;
//     }
//     return find(arr,l,r,x);
// }
// int main(){
//     int x;
//     cout<<"The element you need to search in the array:";
//     cin>>x;
//     int arr[]={1,1,2,3,3,0,0,0};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     cout<<remove(arr,0,n-1,x);
//     return 0;
// }
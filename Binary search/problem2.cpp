// //1st approach
// #include<iostream>
// using namespace std;
// int peak_index(int arr[],int lo,int hi){
//     while(lo<hi){

//         int mid=(hi+lo)/2;
//         if(arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1]){  //viase equal toh honge nhi because given in question,but jab ek sorted increasing array hoga,uss case mein = ki jarurat hai 
//             return mid;
//         }
//         else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1]){
//             lo=mid+1;
//         }
//         else if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1]){
//             hi=mid-1;
//         }
//     }
//     return -1;
// } 
// int main(){
//     int arr[]={7,6,5,4};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     cout<<peak_index(arr,0,n-1);
//     return 0;

// }


//2nd approach
#include<iostream>
using namespace std;
int peak_index(int arr[],int lo,int hi){
    int ans=-1;
    while(lo<hi){
        int mid=(hi+lo)/2;
        if(arr[mid]>arr[mid-1]){ 
            ans=mid;    //we can write ans=max(mid,ans);
            lo=mid+1;
        }
        else if(arr[mid]>arr[mid+1]){
            hi=mid-1;
        }
    }
    return ans;
} 
int main(){
    int arr[]={4,5,6,7,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<peak_index(arr,0,n-1);
    return 0;

}

// #include<iostream>
// using namespace std;
// int peak_element(int arr[],int lo,int hi,int n){
//     while(lo<=hi){
//         int mid=(lo+hi)/2;
//         if(mid==0){
//             if(arr[mid]>=arr[mid+1]){
//                 return 0;
//             }
//             else{
//                 return 1;
//             }
//         }
//         else if(mid==n-1){
//             if(arr[mid]>=arr[mid-1]){
//                 return n-1;
//             }
//             else{
//                 return n-2;
//             }
//         }
//         else{
//         if(arr[mid]>arr[mid-1] && arr[mid+1]<arr[mid]){
//             return mid;
//         }
//         else if(arr[mid]>arr[mid-1]){ //you are on increasing side
//             lo=mid+1;
//         }
//         else{  // you are on decreasing side
//             hi=mid-1;
//         }
//         }
//     }
//     return -1;
// }
// int main(){
//     int n;
//     cout<<"The size of array is:";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     cout<<peak_element(arr,0,n-1,n);
//     return 0;
// }


// #include<iostream>
// #include<vector>
// using namespace std;
// bool search(vector<vector<int>> &v,int target){
//     int n=v.size();
//     int m=v[0].size();
//     int lo=0,hi=n*m-1;
//     while(lo<=hi){
//         int mid=(lo+hi)/2;
//         int x=mid/m;
//         int y=mid%m;
//         if(v[x][y]==target){
//             return true;
//         }
//         else if(v[x][y]>target){
//             hi=mid-1;
//         }
//         else{
//             lo=mid+1;
//         }
//     }
//     return false;
// }
// int main(){
//     int x;
//     cin>>x;
//     vector<vector<int>> v={{1,5,7,9},{10,15,17,20},{23,45,67,89}};
//     cout<<search(v,x);
// }

// //finding the kth smallest element  //mine version is given at the end of the page.
// #include<iostream>
// using namespace std;
// void swap(int &a,int &b){
//     int temp=a;
//     a=b;
//     b=temp;
// }
// int partition(int arr[],int start,int end){
//     int pivot=arr[end];
//     int i=start;
//     for(int j=start;j<end;j++){
//        if(arr[j]<pivot){
//         swap(arr[i],arr[j]);
//         i++;
//        }
//     }
//     swap(arr[i],arr[end]);
//     return i;
// }
// int kth_smallest(int arr[],int l,int r,int k){
//     if(k>0 && k<=(l-r+1)){
//         int pos=partition(arr,l,r);
//         if(pos-l==k-1){
//             return arr[pos];
//         }
//         else if(k-1<pos-l){
//            return kth_smallest(arr,l,pos-1,k);
//         }
//         else{
//             return kth_smallest(arr,pos+1,r,k-(pos-l+1));
//         }
//     }
//     else{
//         return -1;
//     }
// }
// int main(){
//     int arr[]={6,3,2,8,1,5,4,7};
//     int k;
//     cout<<"The value of k is:";
//     cin>>k;
//     cout<<kth_smallest(arr,0,7,k);
// }



// // //merging two sorted arrays;
// // #include<iostream>
// // using namespace std;
// // void merge(int arr1[],int n1,int arr2[],int n2,int arr3[]){
// //     int a=0,b=0,c=0;
// //     while(a<n1 && b<n2){
// //         if(arr1[a]<arr2[b]){
// //             arr3[c++]=arr1[a++];
// //         }
// //         else{
// //             arr3[c++]=arr2[b++];
// //         }
// //     }
// //     while(a<n1){
// //         arr3[c++]=arr1[a++];
// //     }
// //     while(b<n2){
// //         arr3[c++]=arr2[b++];
// //     }
// // }
// // int main(){
// //     int arr1[]={3,6,7};
// //     int n1=sizeof(arr1)/sizeof(arr1[0]);
// //     int arr2[]={1,2,4,6,9};
// //     int n2=sizeof(arr2)/sizeof(arr2[0]);
// //     int arr3[n1+n2];
// //     merge(arr1,n1,arr2,n2,arr3);
// //     for(int i=0;i<n1+n2;i++){
// //         cout<<arr3[i]<<" ";
// //     }
// //     return 0;
// // }



//to find the kth smallest  ele using quick sort
#include<bits/stdc++.h>
using namespace std;
int parition(int arr[],int l,int r){
    int curr_ele=arr[r];
    int i=l-1;
    for(int j=l;j<=r-1;j++){
        if(arr[j]<curr_ele){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
int kth_largest(int arr[],int l,int r,int k){

        int pos=parition(arr,l,r);

        if(pos==k){
            return arr[pos];
        }
        else if(pos<k){
           return kth_largest(arr,pos+1,r,k);
        }
        else{
            return kth_largest(arr,l,pos-1,k);
        }
    
}
int main(){
    int arr[]={6,3,2,8,1,5,4,9,9,7,7,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<<"The value of k is:";
    cin>>k;
    if(k<0 || k>size){
        cout<<"Wrong input for k";
    }
    else{
        cout<<kth_largest(arr,0,11,size-k);
    }
}


//to find the kth largest  ele using quick sort
#include<bits/stdc++.h>
using namespace std;
int parition(int arr[],int l,int r){
    int curr_ele=arr[r];
    int i=l-1;
    for(int j=l;j<=r-1;j++){
        if(arr[j]<curr_ele){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
int kth_smallest(int arr[],int l,int r,int k){

        int pos=parition(arr,l,r);

        if(pos==k-1){
            return arr[pos];
        }
        else if(pos<k-1){
           return kth_smallest(arr,pos+1,r,k);
        }
        else{
            return kth_smallest(arr,l,pos-1,k);
        }
    
}
int main(){
    int arr[]={6,3,2,8,1,5,4,9,9,7,7,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<<"The value of k is:";
    cin>>k;
    if(k<0 || k>size){
        cout<<"Wrong input for k";
    }
    else{
        cout<<kth_smallest(arr,0,11,k);
    }
}
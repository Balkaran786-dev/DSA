#include<iostream>
using namespace std;
void merge(int arr[],int l,int mid,int r){   /*we are passing array as it is with no ampersand operator
                                                beacuse array name is iteself a pointer pointing to the array first
                                                element address.hence when we perform operations on array in a function
                                                they can be seen in the original array also.*/
    int an=mid-l+1;
    int bn=r-mid;
    int a[an],b[bn];  //we take two temporary arrays to put the half elemnt in the 1st and other half in 2nd array.
    for(int i=0;i<an;i++){
        a[i]=arr[l+i];
    }
    for(int j=0;j<bn;j++){
        b[j]=arr[mid+1+j];
    }

    int i=0;
    int j=0;
    int k=l;  // to insert the element of array a and b in increasing order in arr..
    while(i<an && j<bn){
        if(a[i]<=b[j]){
            arr[k++]=a[i++];
        }
        else{
            arr[k++]=b[j++];
        }
    }
    while(i<an) arr[k++]=a[i++];  //if b is fully filled in arr,we need to just fill leftover a elements in arr
    while(j<bn) arr[k++]=b[j++];  //if a is fully filled in arr,we need to just fill leftover b elements in arr
}
void mergesort(int arr[],int l,int r){
    if(l>=r) return;
    int mid=(l+r)/2;
    mergesort(arr,l,mid);  
    mergesort(arr,mid+1,r);  //both split the array into two halves.
    merge(arr,l,mid,r);  //merge the sorted arrays.
}
int main(){
    int arr[]={7,8,4,5,2,9,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


// #include<iostream>
// using namespace std;
// void swap(int &a,int &b){
//     int temp=a;
//     a=b;
//     b=temp;
// }
// void print(int arr[],int n){
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }
// int partition(int arr[],int first,int last){
//      int pivot_element=arr[last];
//      int i=first-1; //to swap the elements<pivot with the initial bigger elements.
//      for(int j=first;j<=last-1;j++){  //here j has been taken to find elements that are lesser than pivot
//         if(arr[j]<pivot_element){
//             i++;
//             swap(arr[i],arr[j]);
//         }
//      }
//      //now i is pointing to the last element<pivot.
//      //correct position for pivot is i+1.
//      swap(arr[i+1],arr[last]);
//      return i+1;
// }
// void quicksort(int arr[],int first,int last){
//     if(first>=last) return;
//     int pi=partition(arr,first,last);
//     quicksort(arr,first,pi-1);
//     quicksort(arr,pi+1,last);
// }
// int main(){
//     int arr[]={18,12,30,16,35,20};
//     quicksort(arr,0,5);
//     print(arr,6);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int partition_ele(int arr[],int first,int last){
    int curr_ele=arr[last];
    int i=first-1;
    for(int j=first;j<=last-1;j++){
        if(arr[j]<curr_ele){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[last]);
    return i+1;
}
void quicksort(int arr[],int first,int last){
    if(first>=last) return;
    int pi=partition_ele(arr,first,last);
    quicksort(arr,first,pi-1);
    quicksort(arr,pi+1,last);
}
int main(){
    int arr[]={18,12,30,16,35,90};
    quicksort(arr,0,5);
    print(arr,6);
    return 0;
}

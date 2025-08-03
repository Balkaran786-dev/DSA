#include<iostream>
using namespace std;  // print all elements of array
void print(int array[],int idx,int length){
    if(length==idx){
        return;
    }
    print(array,idx+1,length);
    cout<<array[idx]<<endl;
}
// }
// int main(){
//     int arr[]={1,2,3,4,5,6};
//     int length=6;
//     print(arr,0,6);  
// }

   // max element of array
// int f(int *arr,int idx,int length){
//     if(idx==length-1){
//         return arr[idx];
//     }
//     return max(arr[idx],f(arr,idx+1,length));
// }
int main(){
    int array[]={1,9,8,7,5,2};
    int length=6;
    print(array,0,6);  // arr represents the pointer that points to the adress of first element
    return 0;
}

//   //sum of all elements of array

// int sum(int *arr,int idx,int length){
//     if(idx==length-1){
//         return arr[idx];
//     }
//     return arr[idx]+sum(arr,idx+1,length);
// }
// int main(){
//     int array[]={1,2,3,4,5,6,7};
//     int length=7;
//     cout<<sum(array,0,length);
// }

#include<bits/stdc++.h>  //o(n)-Time complexity o(1)-space complexity
using namespace std;
void reverse_array(int arr[],int n){
    int count=0;
    int low=0,high=n-1;
    while(low<high){
        count++;
        swap(arr[low++],arr[high--]);
    }
    cout<<"The count of running loop is: "<<count<<endl;
}
int main(){
    int n;
    cout<<"The size of array is:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    reverse_array(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nName: Balkaran singh\nRollNo: 23103027\n";
    return 0;
}
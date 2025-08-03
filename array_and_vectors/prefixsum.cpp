#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the size:";
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    
    for(int i=0;i<n;i++){
        if(i==0){
            continue;
        }else{
            array[i]=array[i]+array[i-1];
        }
    }
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    
    // int n;
    // cout<<"enter the size:";
    // cin>>n;
    // int array[n];
    // for(int i=0;i<n;i++){
    //     cin>>array[i];
    // }
    // int sum=0;
    // for(int i=0;i<n;i++){
    //     sum+=array[i];
    // }
    // int prefixSum=0;
    // for(int i=0;i<n;i++){
    //    prefixSum+=array[i];
    //    if(sum-prefixSum == prefixSum){
    //      cout<<"subarray1:";
    //      for(int j=0;j<=i;j++){
    //         cout<<array[j]<<" ";
    //      }
    //      cout<<endl<<"subarray2:";
    //      for(int j=i+1;j<n;j++){
    //         cout<<array[j]<<" ";
    //      }
    //    }
    //    else{
    //     continue;
    //    }
    // }
    return 0;
}
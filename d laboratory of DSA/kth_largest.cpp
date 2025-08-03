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
    cout<<endl;
    cout<<"Balkaran singh  23103027";
}

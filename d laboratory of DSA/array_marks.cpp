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
    int arr[]={50,40,10,20,30};
    int size=sizeof(arr)/sizeof(arr[0]);
    int second_largest=kth_largest(arr,0,4,size-2);
    cout<<"Following are the marks that have at-least two greater marks than themselves:- "<<endl;
    for(int i=0;i<size;i++){
        if(arr[i]<second_largest){
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
    cout<<"Balkaran singh  23103027";
}


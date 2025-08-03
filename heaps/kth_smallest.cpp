#include<iostream>
using namespace std;
void heapify(int minheap[],int size,int curr){
    while((2*curr+1)<size){   //means till the leaf child of curr node exist
        int left_child=2*curr+1;
        int right_child=2*curr+2;
        int min_child=left_child;
        if(right_child<size && minheap[right_child]<minheap[left_child]){
            min_child=right_child;
        }
        if(minheap[curr]<minheap[min_child]){
            return;
        }
        swap(minheap[min_child],minheap[curr]);
        curr=min_child;
    }
}
int kth_smallest(int minheap[],int size,int k){
    //1.using heapify to create a minheap.
    for(int i=size/2-1;i>=0;i--){
        heapify(minheap,size,i);
    }
    
    //2.deleting k-1 nodes from minheap
    for(int i=1;i<=k-1;i++){
        minheap[0]=minheap[size-1];
        size--;
        heapify(minheap,size,0);
    }
    return minheap[0];
}
int main(){   //you can also do by 0 based indexing
    int arr[]={7,10,4,3,20,15};
    int size=6;
    int k;
    cin>>k;
    int ans=kth_smallest(arr,size,k);
    cout<<ans;
    return 0;
}
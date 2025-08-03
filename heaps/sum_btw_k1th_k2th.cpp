#include<iostream>
using namespace std;
void heapify(int minheap[],int size,int curr){
    while(2*curr+1<size){
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
int sum_btw_k1th_and_k2th(int minheap[],int size,int k1,int k2){
    //1.using heapify to create a minheap.
    for(int i=(size/2)-1;i>=0;i--){
        heapify(minheap,size,i);
    }
    
    //2.deleting k1-1 nodes from minheap  beacuse we are using 0 based indexing
    for(int i=1;i<=k1;i++){
        minheap[0]=minheap[size-1];
        size--;
        heapify(minheap,size,0);
    }
    int sum=0;
    for(int i=1;i<=(k2-k1)-1;i++){
        sum+=minheap[0];
        minheap[0]=minheap[size-1];
        size--;
        heapify(minheap,size,0);
    }
    return sum;
}
int main(){   //you can also do by 0 based indexing

    int arr[]={20,8,22,4,12,10,14};
    int size=7;
    int k1,k2;
    cin>>k1>>k2;
    int sum=sum_btw_k1th_and_k2th(arr,size,k1,k2);
    cout<<sum;

    return 0;
}
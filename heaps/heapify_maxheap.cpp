#include<bits/stdc++.h>
using namespace std;
int const N=1e3;
void heapify(int maxheap[],int size){
    int last_parent_node=size/2; //becuse first leaf node starts from (n/2)+1
    while(last_parent_node!=0){  //traversing all the parent nodes
         int curr=last_parent_node;
         while(curr<(size/2)+1){ //curr node should not come to a leaf node
              int left_child=2*curr;
              int right_child=2*curr+1;
              int max_child=left_child;

            if(right_child<=size && maxheap[right_child]>maxheap[left_child]){
                 max_child=right_child;
            }

            if(maxheap[curr]>maxheap[max_child]){
                 break;
            }
            swap(maxheap[max_child],maxheap[curr]);
            curr=max_child;
         }
         last_parent_node--;
     }
}
int main(){
    int BT[N]={-1,60,10,80,50,5,20,70};
    int size=7; //actually hamne 0th index pe nhi dalna hai.
    int value=5;
    for(int i=0;i<=size;i++){
        cout<<BT[i]<<" ";
    }cout<<endl;
    heapify(BT,size);
    for(int i=0;i<=size;i++){
        cout<<BT[i]<<" ";
    }cout<<endl;
    return 0;
} 
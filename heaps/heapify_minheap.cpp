#include<bits/stdc++.h>
using namespace std;
int const N=1e3;
// void heapify(int minheap[],int size){
//     int last_parent_node=size/2; //becuse first leaf node starts from (n/2)+1
//     while(last_parent_node!=0){
//          int curr=last_parent_node;
//          while(curr<(size/2)+1){ //curr node should not come to a leaf node
//               int left_child=2*curr;
//               int right_child=2*curr+1;
//               int min_child=left_child;

//             if(right_child<=size && minheap[right_child]<minheap[left_child]){
//                  min_child=right_child;
//             }

//             if(minheap[curr]<minheap[min_child]){
//                  break;
//             }
//             swap(minheap[min_child],minheap[curr]);
//             curr=min_child;
//          }
//          last_parent_node--;
//      }
// }

void heapify(int minheap[],int size){
    int leafnode=size/2;
    while(leafnode>0){
        int curr=leafnode;
        while(curr<(size/2)+1){
            int left_child=2*curr;
            int right_child=2*curr+1;
            int min_child=left_child;

            if(right_child<=size && minheap[right_child]<minheap[left_child]){
                min_child=right_child;
            }

            if(minheap[curr]<minheap[min_child]) break;

            swap(minheap[curr],minheap[min_child]);
            curr=min_child;
        }
        leafnode--;
    }
    
}
int main(){
    int minheap[N]={-1,60,10,80,50,5,20,70};
    int size=7; //actually hamne 0th index pe nhi dalna hai.
    int value=5;
    for(int i=0;i<=size;i++){
        cout<<minheap[i]<<" ";
    }cout<<endl;
    heapify(minheap,size);
    for(int i=0;i<=size;i++){
        cout<<minheap[i]<<" ";
    }cout<<endl;
    return 0;
} 
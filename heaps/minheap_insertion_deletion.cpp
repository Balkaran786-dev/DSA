#include<bits/stdc++.h>
using namespace std;
int const N=1e3;
// void insertMinHeap(int minheap[],int &size,int value){
//       size++;
//       minheap[size]=value;
//       int curr=size;

//       while(curr!=1 && minheap[curr/2]>minheap[curr]){
//         swap(minheap[curr],minheap[curr/2]);
//         curr=curr/2;
//       }
// }

// void removeMinHeap(int minheap[],int &size){
//      minheap[1]=minheap[size];
//      size--;

//      int curr=1;

//      while(curr<(size/2)+1){ //traverse until we reach a leaf node,as we know,first leaf node starts from (n/2)+1
//        int left_child=2*curr;
//        int right_child=2*curr+1;
//        int min_child=left_child;

//        if(right_child<=size && minheap[right_child]<minheap[left_child]){ //checking if right child is present and lesser than left child.
//             min_child=right_child;
//        }

//        if(minheap[curr]<minheap[min_child]){ //checking if min child is already greater than parent node,we don't need to do anything,minheap prop is satisfied,hence return
//         return;
//        }

//        swap(minheap[curr],minheap[min_child]);  //if not,swap both the values.
//        curr=min_child;    //curr ko minchild pe le ayo.
//      }
// }

void insertMinHeap(int minheap[],int &size,int value){
     size++;
     minheap[size]=value;
     int curr=size;
     while(curr!=1 && minheap[curr/2]>minheap[curr]){
      swap(minheap[curr/2],minheap[curr]);
      curr=curr/2;
     }
}
void removeMinHeap(int minheap[],int &size){
     minheap[1]=minheap[size];
     size--;

     int curr=1;
     while(curr<(size/2)+1){
       int left_child=2*curr;
       int right_child=2*curr+1;
       int min_child=left_child;

       if(right_child<=size && minheap[min_child]>minheap[right_child]){
        min_child=right_child;
       }

       if(minheap[min_child]>minheap[curr]) return;

       swap(minheap[min_child],minheap[curr]);
       curr=min_child;
     }
}
int main(){
    int minheap[N]={-1,10,20,30,40,50};
    int size=5; //actually hamne 0th index pe nhi dalna hai.
    int value=5;
    insertMinHeap(minheap,size,value);
    for(int i=0;i<=size;i++){
        cout<<minheap[i]<<" ";
    }cout<<endl;
    removeMinHeap(minheap,size);
    for(int i=0;i<=size;i++){
        cout<<minheap[i]<<" ";
    }cout<<endl;

    return 0;
} 
#include<bits/stdc++.h>
using namespace std;
int const N=1e3;
// void insertMaxHeap(int maxheap[],int &size,int value){
//       size++;
//       maxheap[size]=value;
//       int curr=size;
//       while((curr/2)>0 && maxheap[curr/2]<maxheap[curr]){
//         swap(maxheap[curr],maxheap[curr/2]);
//         curr=curr/2;
//       }
// }
// void removeMaxHeap(int maxheap[],int &size){
//      maxheap[1]=maxheap[size];
//      size--;

//      int curr=1;

//      while(2*curr<=size){
      //  int left_child=2*curr;
      //  int right_child=2*curr+1;
      //  int max_child=left_child;

//        if(right_child<=size && maxheap[right_child]>maxheap[left_child]){
//             max_child=right_child;
//        }
       
      //  if(maxheap[curr]>maxheap[max_child]){
      //   return;
      //  }

      //  swap(maxheap[curr],maxheap[max_child]);
      //  curr=max_child;
//      }
// }

void insertMaxHeap(int maxheap[],int &size,int value){
    size++;
    maxheap[size]=value;
    int curr=size;
    while(curr!=1 && maxheap[curr/2]<maxheap[curr]){
      swap(maxheap[curr],maxheap[curr/2]);
      curr=curr/2;
    }
}

void removeMaxHeap(int maxheap[],int &size){
  maxheap[1]=maxheap[size];
  size--;

  int curr=1;
  while(curr<(size/2)+1){
    int left_child=2*curr;
    int right_child=2*curr+1;
    int max_child=left_child;

    if(right_child<=size && maxheap[max_child]<maxheap[right_child]){
      max_child=right_child;
    }
    
    if(maxheap[curr]>maxheap[max_child]){
        return;
       }

       swap(maxheap[curr],maxheap[max_child]);
       curr=max_child;

  }
}
int main(){
    int maxheap[N]={-1,60,50,40,30,20,30,10};
    int size=7; //actually hamne 0th index pe nhi dalna hai.
    int value=100;
    insertMaxHeap(maxheap,size,value);
    for(int i=0;i<=size;i++){
        cout<<maxheap[i]<<" ";
    }cout<<endl;
    removeMaxHeap(maxheap,size);
    for(int i=0;i<=size;i++){
        cout<<maxheap[i]<<" ";
    }cout<<endl;
    return 0;
}
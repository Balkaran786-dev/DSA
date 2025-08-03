// //using max_heap

// #include<bits/stdc++.h>  //o(nlogn)-time
// using namespace std;
// int const N=1e3;
// void heapify(int maxheap[],int size,int curr){
         
//          while(curr<(size/2)+1){ //curr node should not come to a leaf node
//               int left_child=2*curr;
//               int right_child=2*curr+1;
//               int max_child=left_child;

//             if(right_child<=size && maxheap[right_child]>maxheap[left_child]){
//                  max_child=right_child;
//             }

//             if(maxheap[curr]>maxheap[max_child]){
//                 return;
//             }
//             swap(maxheap[max_child],maxheap[curr]);
//             curr=max_child;
//          }
         
// }
// void heap_sort(int BT[],int n){
//     //1. heapify the given BT into maxheap.
//     for(int i=n/2;i>0;i--){  //i ke neeche vale sare nodes ko heapify karunga,means maxheap mein arrange karunga
//         heapify(BT,n,i);
//     }
    
//     //2. keep deleting elements from the BT until size becomes zero.
//     //we r originaly not deleting ele,but storing them at the last node and decreasing our array size.
//     for(int i=n;i>0;i--){
//         swap(BT[1],BT[i]);
//         n--;
//         heapify(BT,n,1);  //hume hamesha 1 se hi heapify krna hoga.
//     }

// }

// int main(){
//     int BT[N]={-1,89,-23,1,5,-667,67,55};
//     int size=7; //actually hamne 0th index pe nhi dalna hai.
//     heap_sort(BT,size);
//     for(int i=1;i<=size;i++){
//         cout<<BT[i]<<" ";
//     }cout<<endl;
//     return 0;
// } 






//using min_heap

#include<bits/stdc++.h>  //o(nlogn)-time
using namespace std;
int const N=1e3;
void heapify(int minheap[],int size,int curr){
         
         while(curr<(size/2)+1){ //curr node should not come to a leaf node
              int left_child=2*curr;
              int right_child=2*curr+1;
              int min_child=left_child;

            if(right_child<=size && minheap[right_child]<minheap[left_child]){
                 min_child=right_child;
            }

            if(minheap[curr]<minheap[min_child]){
                return;
            }
            swap(minheap[min_child],minheap[curr]);
            curr=min_child;
         }
         
}
void heap_sort(int BT[],int n){
    //1. heapify the given BT into minheap.
    for(int i=n/2;i>0;i--){  //i ke neeche vale sare nodes ko heapify karunga,means minheap mein arrange karunga
        heapify(BT,n,i);
    }
    
    //2. keep deleting elements from the BT until size becomes zero.
    //we r originaly not deleting ele,but storing them at the last node and decreasing our array size.
    for(int i=n;i>0;i--){
        swap(BT[1],BT[i]);
        n--;
        heapify(BT,n,1);  //hume hamesha 1 se hi heapify krna hoga.
    }

}

int main(){
    int BT[N]={-1,89,23,1,-5,667,67,-55};
    int size=7; //actually hamne 0th index pe nhi dalna hai.
    heap_sort(BT,size);
    for(int i=1;i<=size;i++){
        cout<<BT[i]<<" ";
    }cout<<endl;
    return 0;
} 
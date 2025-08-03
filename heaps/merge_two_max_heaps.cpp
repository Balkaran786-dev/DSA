#include<iostream>  //o(n+m)
#include<vector>
using namespace std;
class solution{
      void heapify(vector<int> &maxheap,int size,int curr){
         //in case of 0 based indexing:
         //1.leftchild=2*curr+1
         //2.rightchild=2*curr+2
          while((2*curr)+1<size){  //till the node that has a left node,means parent node hi hogi
            int left_child=2*curr+1;
              int right_child=2*curr+2;
              int max_child=left_child;

            if(right_child<size && maxheap[right_child]>maxheap[left_child]){
                 max_child=right_child;
            }

            if(maxheap[curr]>maxheap[max_child]){
                 return;
            }
            swap(maxheap[max_child],maxheap[curr]);
            curr=max_child;
          }
      }
public: 
      vector<int> merge_heaps(vector<int> &heap1,vector<int> &heap2,int n,int m){
        vector<int> mergedheap;
        for(int ele:heap1){
            mergedheap.push_back(ele);
        }
        for(int ele:heap2){
            mergedheap.push_back(ele);
        }
        int last_parent_node=((n+m)/2)-1;  //in 1 based index,it is (n+m)/2,but in 0 based,it is ((n+m)/2)-1
        for(int i=last_parent_node;i>=0;i--){
            heapify(mergedheap,n+m,i);
        }
        return mergedheap;
      }
};
int main(){
  
    vector<int> heap1={10,5,6,2};
    vector<int> heap2={12,7,9};
    solution s;
    vector<int> mergedheap=s.merge_heaps(heap1,heap2,heap1.size(),heap2.size());
    for(int ele:mergedheap){
        cout<<ele<<" ";
    }
    return 0;
}
#include<iostream>
using namespace std;
int largestElementIndex(int array[],int size){
    int max=INT16_MIN;
    int maxIndex;
    for(int i=0;i<size;i++){
        if(array[i]>max){
            max=array[i];
            maxIndex=i;
        }    
    }
    return maxIndex;
}
int main(){
    int a[]={1,4,7,7,5,7,6};
    int largestEleIndex=largestElementIndex(a,7);
    int largestElement=a[largestEleIndex];
    cout<<largestElement<<endl;
    for(int i=0;i<7;i++){
        if(a[i]==largestElement){
            a[i]=-1;
        }
    }
    int secondLargestEleIndex=largestElementIndex(a,7);
    cout<<a[secondLargestEleIndex];
    
}
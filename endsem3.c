#include<stdio.h>
int binarysearch(int array[],int n,int key){
    int s=0,e=n;
    while(s<=e){
       int mid=(s+e)/2;
       if(array[mid]==key){
        return mid;
       }
       else if(array[mid]<key){
        s=mid+1;
       }
       else{
        e=mid-1;
       }
    }
    return -1;
}
int main(){
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int key;
    printf("Enter the value you want to search:");
    scanf("%d",&key);
    int array[n];
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    printf("%d",binarysearch(array,n,key));
    return 0;
}
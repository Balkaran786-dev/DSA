     // deletion
#include<stdio.h>
int main(){
    int arr[]={1,2,3,4,5,6};
    int pos;
    scanf("%d",&pos);
   for(int i=pos;i<=4;i++){
     arr[i]=arr[i+1];
   }
    for(int i=0;i<=4;i++){
       printf("%d ",arr[i]);
    }
}

   // insertion
#include<stdio.h>
int main(){
    int arr[]={1,2,3,4,6,7};
    int pos,ele;
    scanf("%d %d",&pos,&ele);
    for(int i=5;i>=pos;i--){
        arr[i+1]=arr[i];
    }
    arr[pos]=ele;
    for(int i=0;i<=6;i++){
       printf("%d ",arr[i]);
    }
}
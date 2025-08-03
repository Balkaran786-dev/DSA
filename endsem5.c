// #include<stdio.h>
// #include<string.h>
// int main(){
//     char str[]="college wallah";
//     char *ptr=str;          // instead use &str[0].
//     printf("%c",ptr);
// }

// #include<stdio.h>
// #include<string.h>
// int main(){
//     int n;
//     printf("Enter the no. of string to be sorted:");
//     scanf("%d",&n);
//     char str[n][20],temp[100];
//     for(int i=0;i<=n;i++){
//        gets(str[i]);
//     }
//     for(int i=0;i<=n;i++){
//         for(int j=i+1;j<=n;j++){
//             if(strcmp(str[i],str[j])>0){
//                 strcpy(str[i],temp);
//                 strcpy(temp,str[j]);
//                 strcpy(str[j],str[i]);
//             }
//         }
//     }
//     printf("The sorted output of the string is:");
//     for(int i=0;i<=n;i++){
//         puts(str[i][]);
//     }
//     return 0;
// }

#include<stdio.h>
int binarysearch(int array[],int l,int h,int key){
    if(l==h){
        if(array[l]==key){
           return l;
        }
        else{
            return -1;
        }
    }
    else{
        int mid=(l+h)/2;
        if(array[mid]==key){
            return mid;
        }
        else if(array[mid]>key){
            return binarysearch(array,l,mid-1,key);
        }
        else{
            return binarysearch(array,mid+1,h,key);
        }
    }
}
int main(){
    int array[]={10,20,30,40,50};
    printf("%d",binarysearch(array,0,5,50));
}
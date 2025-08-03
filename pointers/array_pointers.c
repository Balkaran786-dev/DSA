#include<stdio.h>
int main(){
  // int a=9;
  // int b=2;
  // int *ptr=&a;
  // int **p=&ptr;
  // printf("%d %d %d %d\n",ptr,*ptr,**p,*p);
  // *p=&b;
  // printf("%d",*ptr);
 
// // array and pointer
// int a[5]={10,20,30,40,50};
// int *p=a;
// for(int i=0;i<5;i++){      
//     printf("%d\n",p[i]);
// }                           //through all three ways you can traverse a array
// /*for(int i=0;i<5;i++){
//     printf("%d\n",*(p+i));
// }*/
// for(int i=0;i<5;i++){
//     printf("%d\n",*(p));
//     p++;
// }

// pointer to a whole array
//   int a[5]={1,2,3,4,5};
//   int (*ptr)[5]=&a;  // p and *p both will give the address of first element of array
//   for(int i=0;i<5;i++){
//     printf("%d\n",*(*ptr+i));  //or you can use(*ptr)[i]
//   }

// array of pointers
//    int arr[3]={1,2,3};
//    int *ptr[3];
//    for(int i=0;i<3;i++){
//         ptr[i]=&arr[i];
//    }
//    for(int i=0;i<3;i++){    //ptr is actually having the address of the elements..*ptr[i] will give the value of the element
//     printf("%d ",*ptr[i]); // print all elements of the array
//    }
    return 0;
}
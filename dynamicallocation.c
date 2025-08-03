#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("ENTER THE NUMBER OF INTEGERS YOU WANT:");
    scanf("%d",&n);
                        //u can use calloc or malloc for this
    int* ptr=(int*) calloc(n,sizeof(int));  //basically securing a block of memory for our use
    int* p=ptr;
    for(int i=1;i<=n;i++){
        scanf("%d",&(*ptr));
        ptr++;
    }
    for(int i=1;i<=n;i++){
        printf("%d ",(*p));
        p++;
    }

}
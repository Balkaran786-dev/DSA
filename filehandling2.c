#include<stdio.h>
int main(){
    FILE* fileptr=fopen("test.txt","w");
    char str[50]="Hello Everyone,My name is Balkaran singh. \nI work at Microsoft.";
    fputs(str,fileptr);
    fclose(fileptr);
    return 0;
}
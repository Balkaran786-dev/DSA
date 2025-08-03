#include<stdio.h>
int main(){
    FILE* fileptr=fopen("balkaran.txt","r");  // basically opening a file whose name is "balkaran"
     char str[100];     // used to print what is written inside the file.
    while(fgets(str,100,fileptr)!=NULL){
            printf("%s",str);
    }

    FILE* ptr=fopen("PW.txt","w"); // creating a file with name "PW"
    return 0;
}
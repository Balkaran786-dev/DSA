#include<stdio.h>
int main(){
    char str[15]="college wallah";  // size is 15  one spce is given to \0 ..you can even write more than 15 size between the brackets but not less then 15....
    int i=0;
    while(str[i]!='\0'){
        printf("%c",str[i]);
        i++;
    }

    printf("\n");

    str[1]=97;
    str[0]='B';
    int j=0;
    while(str[j]!='\0'){
        printf("%c",str[j]);  // you can write like:  j[str],*(str+j),*(j+str) to access a particular element. 
        j++;
    }*/

    char str[50];
    puts("Enter the string:");
    gets(str);
    int size=0; 
    int j=0;              
    while(str[j]!='\0'){
        size+=1;
        j++;
    }
    int numberofwords=0;
    for(int i=0;i<size;i++){
       if(str[i]>=65 && str[i]<=90){
        numberofwords+=1;
       }
    }
    
    printf("%d",numberofwords+1);
    return 0;
}
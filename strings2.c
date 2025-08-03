#include<stdio.h>
#include<string.h>
int main(){
    /*char str[20];
    puts("Enter the string:");  // (give automaticaly \n) 
    gets(str);
    puts("The string is:");
    puts(str);

    // or
    
    char str[20];
    scanf("%[^\n]s",str);    // without [^\n], scanf usually take the word unti any space.. 
    printf("%s",str); */


   // reversing the string
    char str[30];
    printf("Enter the string:");
    scanf("%[^\n]s",str);
    int i=0;
    int size=0;            // determing the size of string    
    while(str[i]!='\0'){
        size+=1;
        i++;
    }
    for(int i=0,j=size-1;i<j;i++,j--){
        int c;
        c=str[i];
        str[i]=str[j];
        str[j]=c;
    }
    puts("The reverse string is:");
    puts(str);
    return 0;
}

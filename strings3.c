#include<stdio.h>
#include<string.h>
int main(){
   /* char str[]="college wallah";
    char *ptr=str;          // instead use &str[0].
    printf("%c",*(ptr+3));

    char str1[]="Balkaran singh";
    str1[0]='V';               // correct
    str1="Karandeep singh";    //incorrect

    char *ptr1="Sukhman";
    ptr1="Ramandeep";         // correct
    ptr1[0]='P';             //incorrect*/

    char str[]="college wallah";
    char *ptr=str;
    ptr="physics wallah";
    printf("%s\n",str);
    printf("%c",*ptr);   // ptr will print the whole string and *ptr will only print the element
   
    *ptr='p';
    printf("%s",str);
    
    return 0;
}
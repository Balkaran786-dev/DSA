#include<stdio.h>
#include<string.h>
int main(){
   char str1[]="codingwallah";
   int size=strlen(str1);
   int flag =0;
   int x,y;
   for(int i=0;i<size-1;i++){
    for(int j=0;j<size-i-1;j++){
         x=str1[j];
         y=str1[j+1];
        if(x>y){
            flag =1;
            char ch;
            ch=str1[j+1];
            str1[j+1]=str1[j];
            str1[j]=ch;
        }
        
    }
    if(flag==0){
            break;
        }
   }

   printf("%s",str1);
    return 0;
}


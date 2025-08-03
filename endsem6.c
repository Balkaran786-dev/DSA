#include<stdio.h>
void foo(int num){
    if(num==0){
        return;
    }
    printf("%d\n",num);
    foo(num-1);
    printf("%d\n",num);
    return;
}
int main(){
    foo(4);
    return 0;
}
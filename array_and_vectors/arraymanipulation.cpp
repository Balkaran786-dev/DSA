#include<iostream>
using namespace std;
int main(){         // in array manipulation we change the required number of elements to a fixed number{like here we converted them into -1}
 /*   int array[]={1,3,2,1,2,4,3};
    int size=7;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(array[i]==array[j]){
                array[i]=array[j]=-1;
            }
        }
    }
    for(int i=0;i<size;i++){
        if(array[i]>0){
            cout<<array[i];
        }
    }*/

    int array[]={1,3,5,8,4,6};
    int size=6;
    int max=0;
    for(int i=0;i<size;i++){
        if(array[i]>max){
            max=array[i];
        }
    }
    max=-1;
    return 0;
}
#include<iostream>
using namespace std;
void sized_array(int a[10]){

    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void unsized_array(int a[],int size){

    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void array_as_pointer(int *p,int size){

    for(int i=0;i<size;i++){
        cout<<*(p+i)<<" ";
    }
    cout<<endl;
}
void array_as_reference(int (&a)[5]){
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    cout<<"\nName: Balkaran singh\nRollNo: 23103027\n";   
    int a[]={1,2,3,4,5};
    int size=5;
    sized_array(a);
    unsized_array(a,size);
    array_as_pointer(a,size);
    array_as_reference(a);
    return 0;
}
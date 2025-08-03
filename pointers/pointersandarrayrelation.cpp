#include<iostream>
using namespace std;
// int main(){
//     int arr[]={1,4,7};
//     int *ptr=arr;
//     cout<<ptr<<endl;
//     cout<<arr<<endl; // name of array is a pointer that stores the address of 1st element of array
//     cout<<*ptr<<" "<<*arr<<endl;
//     cout<<*(ptr+1)<<" "<<*(arr+1); 
//     return 0;
// }

void print(int array[],int n){
    for(int i=0;i<n;i++){
        cout<<*(array+i);
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<array[i];
    }
}
int main(){
    int array[]={1,2,3,4,5};
    print(array,5);
}
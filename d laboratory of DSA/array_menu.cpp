#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"size of array is: ";
    cin>>n;
    int array[n];
    cout<<"Give the values you want to insert in the array:-"<<endl;
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int input1;
    cout<<"press 1 for insertion or press 2 for deletion:- "<<endl;
    cin>>input1;
    switch (input1){
    case 1:
        int value;
        cout<<"Enter the value you want to insert in the array:- "<<endl;
        cin>>value;
        char input2;
        cout<<"press 's' for insertion in start or press 'r' for insertion at any random position or press 'l' to insert at the end of array :-"<<endl;
        cin>>input2;
         cout<<"Array before insertion :-"<<endl;
            for(int i=0;i<n;i++){
                cout<<array[i]<<" ";
            }cout<<endl;
        switch (input2){
        case 's':
            int k;
            for( k=n-1;k>=0;k--){
               array[k+1]=array[k];
            }
            k++;
            array[k]=value;
            cout<<"Array after insertion :-"<<endl;
            for(int i=0;i<n+1;i++){
                cout<<array[i]<<" ";
            }cout<<endl;
            break;
        case 'r':
            int idx;
            cout<<"Enter the position where you want to insert an element:- "<<endl;
            cin>>idx;
            int m;
            for(m=n-1;m>=idx-1;m--){
                array[m+1]=array[m];
            }
            m++;
            array[m]=value;
            cout<<"Array after insertion :-"<<endl;
            for(int i=0;i<n+1;i++){
                cout<<array[i]<<" ";
            }cout<<endl;
            break;
        case 'l':
            array[n]=value;
            cout<<"Array after insertion :-"<<endl;
            for(int i=0;i<n+1;i++){
                cout<<array[i]<<" ";
            }cout<<endl;
            break;
        default:
            cout<<"You have given a wrong input..."<<endl;
            break;
        }
        break;
    case 2:
        char input3;
        cout<<"press 's' to delete the element at the begining or press 'r' to delete an element present at a random position or press 'l' to delete the last element:- "<<endl;
        cin>>input3;
        cout<<"Array before deletion :-"<<endl;
            for(int i=0;i<n;i++){
                cout<<array[i]<<" ";
            }cout<<endl;
        switch (input3)
        {
        case 's':
            for(int i=0;i<n-1;i++){
                array[i]=array[i+1];
            }
            cout<<"Array after deletion :-"<<endl;
            for(int i=0;i<n-1;i++){
                cout<<array[i]<<" ";
            }cout<<endl;
            break;
        case 'r':
            int index;
            cout<<"Enter the position where you want to apply deletion:- "<<endl;
            cin>>index;
            for(int p=index-1;p<=n-1;p++){
                array[p]=array[p+1];
            }
            cout<<"Array after deletion :-"<<endl;
            for(int i=0;i<n-1;i++){
                cout<<array[i]<<" ";
            }cout<<endl;
            break;
        case 'l':
            cout<<"Array after deletion :-"<<endl;
            for(int i=0;i<n-1;i++){
                cout<<array[i]<<" ";
            }cout<<endl;
            break;
        default:
            cout<<"You have given a wrong input..."<<endl;
            break;
        }
        break;
    default:
        cout<<"You have given a wrong input..."<<endl;
        break;
    }

    cout<<"\nName: Balkaran singh\nRollNo: 23103027\n";  
    return 0;
}
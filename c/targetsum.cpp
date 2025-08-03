#include<iostream>
using namespace std;
int main(){

    // target sum problems........
    int array[6];
    for(int i=0;i<6;i++){
        cin>>array[i];
    }
    int sumvalue;
    cout<<"enter the sum value:";
    cin>>sumvalue;
    int pairs=0;
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            if (array[i]+array[j]==sumvalue){
                pairs+=1;
            }
        }
    }
    cout<<"THE NO OF PAIRS:"<<pairs;

    int array[6];
    for(int i=0;i<6;i++){
        cin>>array[i];
    }
    int sumvalue;
    cout<<"enter the sum value:";
    cin>>sumvalue;
    int triplets=0;
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            for(int k=j+1;k<6;k++){
                if(array[i]+array[j]+array[k]==sumvalue){
                    triplets+=1;
                }
            }
        }
    }
    cout<<triplets;

   // ARRAY MANIPULATION 


   int array[6];
   int size=6;
   for(int i=0;i<size;i++){
     cin>>array[i];
   }
   for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
        if (array[i]==array[j]){
            array[i]=-1;
            array[j]=-1;
        }
    }
   }
   for(int i=0;i<size;i++){
    if (array[i]!=-1){
        cout<<array[i];
    }
   }
   
  

    return 0;
}
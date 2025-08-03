#include<iostream>
using namespace std;
int main(){
    // sum of elements of arrays
    int array[]={21,31,41,51,61};
    int sum=0;
    for(int idx=0;idx<5;idx++){
        sum+=array[idx];
    }
    cout<<sum<<endl;

       // printing maximum value from all elements

    int array[]={4,1,67,89,30};
    int size=sizeof(array)/sizeof(array[0]);
    int max=0;
    for(int idx=0;idx<size;idx++){
        if ( max<array[idx]){
            max=array[idx];
        }
        
    }
    cout<<max<<endl;
      
      //LINEAR SEARCH FOR 78
    int array[]={1,23,56,12,11};
    int size=sizeof(array)/sizeof(array[0]);
    for(int idx=0;idx<size;idx++){
        if (array[idx]==78){
            cout<<idx<<endl;
            break;
        } 
        else{
            if(idx==size-1){
                cout<<"-1";
            }
        }
    }   
       //OR   // linear search for 78

    int array[]={1,23,56,12,11};
    int size=sizeof(array)/sizeof(array[0]);
    int ans=-1;
    for(int idx=0;idx<size;idx++){
        if (array[idx]==78){
            ans=idx;
        }
    }
    cout<<ans<<endl;
    

    return 0;
}
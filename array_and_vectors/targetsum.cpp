#include<iostream>
using namespace std;
int main(){

    // target sum problems........
    int array[7];
    for(int i=0;i<7;i++){
        cin>>array[i];
    }
    int sumvalue;
    cout<<"enter the sum value:";
    cin>>sumvalue;
    int triplets=0;
    /*int pairs=0;
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            if (array[i]+array[j]==sumvalue){
                pairs+=1;
            }
        }
    }
    cout<<"THE NO OF PAIRS:"<<pairs;*/
   
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
   int array[7];
   int size=7;
   for(int i=0;i<size;i++){
     cin>>array[i];
   }
   for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
        if (array[i]==array[j]){
            array[j]=-1;
            array[i]=-1;
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




/*#include<iostream>
using namespace std;
int largestElementIndex(int array[],int size){
    int max=INT16_MIN;
    int maxIndex;
    for(int i=0;i<size;i++){
        if(array[i]>max){
            max=array[i];
            maxIndex=i;
        }
    }
    return maxIndex;
}
int main(){
    int a[]={1,4,6,7,7,2,7};
    int indexoflargestElement=largestElementIndex(a,7);
    cout<< a[indexoflargestElement]<<endl;
    int largestelement=a[indexoflargestElement];
    for(int i=0;i<7;i++){
        if(a[i]==largestelement){
            a[i]=-1;
        }
    }
   
    int indexofsecondlargestelement=largestElementIndex(a,7);
    cout<<a[indexofsecondlargestelement];
}  

// we are traversing 3 times in the loop in above method...

#include<iostream>
using namespace std;
int main(){
    int array[]={1,2,7,6,7,5,4};
    int max=INT16_MIN;
    int secondMax=INT16_MIN;
    for(int i=0;i<7;i++){
        if(array[i]>max){
            max=array[i];
        }
    }
    cout<<max<<endl;
    for(int i=0;i<7;i++){
        if(array[i]>secondMax && array[i]!=max){
            secondMax=array[i];
        }
    }
    cout<<secondMax;
    return 0;
}*/




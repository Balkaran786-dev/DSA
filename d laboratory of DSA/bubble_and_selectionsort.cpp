#include<iostream>
using namespace std;
void selectionsort(int array[],int n){
    int count_of_swaps=0;
    int count_of_iteration=0;
    for(int i=0;i<n-1;i++){
        int min_index=i;  //assuming the ith element to be the smallest
        // finding the minimum element index in the unsorted array
        for(int j=i+1;j<n;j++){
            count_of_iteration++;
            if(array[j]<array[min_index]){
              min_index=j;
            }      
        }
        //placing the min element at the beginning of array
        if(min_index!=i){
        count_of_swaps++;
        swap(array[i],array[min_index]); //swapping the min element with the ith element
        }
    }
    cout<<"The count of iterations is: "<<count_of_iteration<<endl;
    cout<<"The count of swaps is: "<<count_of_swaps<<endl;
}
void bubblesort(int array[],int n){
    int count_of_swaps=0;
    int count_of_iteration=0;
    for(int i=0;i<n-1;i++){
        bool flag=false;   // agar pehle hi 1 aur 2 passes mein sorted ban gyi so no need to go ahead..hence taken this flag
        for(int j=0;j<n-1-i;j++){ // -i esliye kyunki har ek pass ke sath ek last element apni correct position pe ajeyega so no need to check it
            count_of_iteration++;
            if(array[j]>array[j+1]){
                count_of_swaps++;
                swap(array[j],array[j+1]);
                flag=true;
            }
        }
        if(!flag){  // only if the swaping doesn't occur even one time,then !flag is true
            break;
        }
    }
    cout<<"The count of iterations is: "<<count_of_iteration<<endl;
    cout<<"The count of swaps is: "<<count_of_swaps<<endl;
}
int main(){
    int n;
    cout<<"The size of array is: "<<endl;
    cin>>n;
    int array[n];
    cout<<"Give the values you want in your array:- "<<endl;;
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int input;
    cout<<"Press (1) to sort by bubble sort algorithm or press (2) to sort by selection sort algorithm:- "<<endl;
    cin>>input;
    switch (input)
    {
    case 1:
        bubblesort(array,n);
        for(int i=0;i<n;i++){
          cout<<array[i]<<" ";
        }
        break;
    case 2:
        selectionsort(array,n);
        for(int i=0;i<n;i++){
          cout<<array[i]<<" ";
        }
        break;
    default:
        cout<<"You have a wrong input.."<<endl;
        break;
    }
    cout<<"\nName: Balkaran singh\nRollNo: 23103027\n";  
}
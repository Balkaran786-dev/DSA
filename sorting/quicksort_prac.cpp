#include<bits/stdc++.h>
using namespace std;

int pivot_ele(vector<int> &vec,int l,int r){
     int pivot_ele=vec[r];
     int i=l-1;
     for(int j=l;j<=r-1;j++){
        if(vec[j]<pivot_ele){
            i++;
            swap(vec[j],vec[i]);
        }
     }
     swap(vec[i+1],vec[r]);
     return i+1;
}

void quicksort(vector<int> &vec,int l,int r,int n){
     if(l>=r) return;
     int k=pivot_ele(vec,l,r);
     quicksort(vec,l,k-1,n);
     quicksort(vec,k+1,r,n);
}

int main(){
   
    int n;
    cout<<"Size of vector:- ";
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    
    quicksort(vec,0,n-1,n);
    
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;

// void print_arr(int arr[], int n){
//     for(int i=0; i<n ;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// int partition(int arr[], int low,int high){
//     int pivot = arr[low];
//     int i = low;
//     int j = high;

//     while(j>i){
//         while(i<high && arr[i] <= pivot){
//             i++;
//         }

//         while(j>low && arr[j] > pivot){
//             j--;
//         }

//         if(j>i) swap(arr[i],arr[j]);

//     }
//     swap(arr[low],arr[j]);
    
//     return j;
// }

// void quick_sort(int arr[], int low,int high){
//     if(low>=high) return;

    
//     int partition_idx = partition(arr,low,high);

//     quick_sort(arr,low,partition_idx - 1);
//     quick_sort(arr,partition_idx + 1,high);

// }

// int main(){
    
//     int arr[]= {1,2,3,4,5,6};
//     int n = sizeof(arr)/sizeof(int);

//     quick_sort(arr,0,n-1);
//     print_arr(arr,n);
// }
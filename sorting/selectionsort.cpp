// #include<iostream>
// #include<vector>
// using namespace std;
// void selectionsort(vector<int> &v,int size){
//     int n=size;
//     for(int i=0;i<n-1;i++){
//         int min_index=i;  //assuming the ith element to be the smallest
//         // finding the minimum element index in the unsorted array
//         for(int j=i+1;j<n;j++){
//             if(v[j]<v[min_index]){
//               min_index=j;
//             }      
//         }
//         //placing the min element at the beginning of array
//         if(min_index!=i){
//         swap(v[i],v[min_index]); //swapping the min element with the ith element
//         }
//     }
// }
// int main(){
//     vector<int> vec={3,100,9,6,1};
//     selectionsort(vec,5);
//     for(int i=0;i<5;i++){
//         cout<<vec[i]<<" ";
//     }
//     return 0;
// }

     // finding the maximum element index first...


#include<iostream>
#include<vector>
using namespace std;
// void selectionsort(vector<int> &v){
//     int n=v.size();
//     for(int i=0;i<n-1;i++){
//         int max_index=n-1-i;
//         for(int j=n-2-i;j>=0;j--){
//             if(v[j]>v[max_index]){
//                 max_index=j;
//             }
//         }
//         if(max_index!=n-1-i){
//             swap(v[n-1-i],v[max_index]);
//         }
//     }
// }
void insertion(vector<int> &v){
    int n=v.size();
    for(int i=1;i<n;i++){
        int curr_ele=v[i];
        int j;
        for(j=i-1;j>=0;j--){
            if(v[j]>curr_ele){
                v[j+1]=v[j];
            }
            else if(v[j]<curr_ele){
                break;
            }
        }
        v[j+1]=curr_ele;
    }
}
int main(){
    vector<int> vec={3,100,9,6,1,2,1};
    insertion(vec);
    for(int i=0;i<7;i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}

// selection sorting algorithm is better than bubble because 
// its maximum number of swaps are (n) whereas in bubble sort max
// number of swaps are (n^2).. In bubble sort, with every swap you don't 
// reach the correct place but just get near to it but In selection sort, you 
// basically an element reaches its correct place after every swap...
#include <bits/stdc++.h> 
using namespace std; 
 
int partition(vector<int>& arr, int low, int high) { 
    int pivot = arr[high]; 
    int i = low; 
    for (int j = low; j < high; j++) { 
        if (arr[j] < pivot) { 
            swap(arr[i], arr[j]); 
            i++; 
        } 
    } 
    swap(arr[i], arr[high]); 
    return i; 
} 
 
int randomizedPartition(vector<int>& arr, int low, int high) { 
    int random = low + rand() % (high - low + 1); 
    swap(arr[random], arr[high]); 
    return partition(arr, low, high); 
} 
void randomizedQuickSort(vector<int>& arr, int low, int high) { 
    if (low < high) { 
        int pi = randomizedPartition(arr, low, high); 
        randomizedQuickSort(arr, low, pi - 1); 
        randomizedQuickSort(arr, pi + 1, high); 
    } 
} 
 
int main() { 
    srand(time(0)); 
    vector<int> arr = {10, 7, 8, 9, 1, 5}; 
 
    randomizedQuickSort(arr, 0, arr.size() - 1); 
 
    cout << "Sorted array: "; 
    for (int i : arr) 
        cout << i << " "; 
    cout << endl; 
 
    return 0; 
} 
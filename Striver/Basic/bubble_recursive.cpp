

class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void helper(vector<int> &arr,int idx,int n){
        if(idx==n-1){
            return;
        }
        bool flag=false;
        for(int i=0;i<=n-idx-2;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                flag=true;
            }
        }
        
        if(!flag) return;
        
        helper(arr,idx+1,n);
    }
    void bubbleSort(vector<int>& arr) {
        // Your code here
        int idx=0;
        int n=arr.size();
        helper(arr,idx,n);
    }
};



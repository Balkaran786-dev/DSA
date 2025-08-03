
class Solution {
  public:
    // Please change the array in-place
    void helper(vector<int>&arr,int idx,int n){
        if(idx>=n){
            return;
        }
        
        int j;
        int ele=arr[idx];
        for(j=idx-1;j>=0;j--){
            if(arr[j]<=ele){
                break;
            }
            else{
                arr[j+1]=arr[j];
            }
        }
        
        arr[j+1]=ele;
        
        helper(arr,idx+1,n);
    }
    void insertionSort(vector<int>& arr) {
        // code here
        int idx=1;
        int n=arr.size();
        helper(arr,idx,n);
    }
};



class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int lo=0;
        int hi=arr.size()-1;
        if(arr[lo]<arr[hi]) return 0;
        
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]>arr[mid+1]){
                ans=mid+1;
                return ans;
            }
            else if(arr[mid]<arr[mid-1]){
                ans=mid;
                return ans;
            }
            else if(arr[mid]>arr[lo]){
                lo=mid+1;
            }
            else if(arr[mid]<arr[hi]){
                hi=mid-1;
            }
        }
        return ans;
    }
};



class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int lo=1; //starting of the array
        int hi=n/2; //ending of the array  //sqaure root of n will always lie between 1 to n/2..
        int ans;
        while(lo<=hi){
           int mid=(lo+hi)/2;  //modified form to tackle overflow mid=lo+(hi-lo)/2
           if(mid*mid<=n){
            ans=mid;
            lo=mid+1;
           }
           else{
            hi=mid-1;
           }
        }
        return ans;
    }
};
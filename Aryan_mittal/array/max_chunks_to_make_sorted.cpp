class Solution {
public:
    int firstSum(int n){
        return (n*(n+1))/2;
    }
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int prefix=0;
        int max_chunks=0;
        for(int i=0;i<n;i++){
            prefix+=arr[i];
            if(prefix==firstSum(i)) max_chunks++;
        }
        return max_chunks;
    }
};
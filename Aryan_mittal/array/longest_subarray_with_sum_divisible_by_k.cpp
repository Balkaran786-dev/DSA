
class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // Complete the function
        int n=arr.size();
        unordered_map<int,int> mp;
        mp[0]=-1;
        int length=0;
        long prefix=0;
        for(int i=0;i<n;i++){
            prefix+=arr[i];
            int remainder=((prefix%k)+k)%k;
            if(mp.find(remainder)!=mp.end()){
                length=max(length,i-mp[remainder]);
            }
            else{
                mp[remainder]=i;
            }
        }
        return length;
    }
};

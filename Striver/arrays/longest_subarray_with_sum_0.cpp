//similar to the ques longest_subarray_with_sum_k, just here k=0;
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<long long,int> mp;
        mp[0]=-1;
        int len=0;
        if(arr[0]==0){ // added this , beacuse may be our array is of 1 size and the first ele is 0, so our down for loop will not work , but our ans should be returned 1,so thats why..
            len=1;
        }

        if(mp.find(arr[0])==mp.end()){  //add this additional point may be the first ele is also zero so we can insert it,beacuse we have already inserted 0 at idx=-1,
            mp[arr[0]]=0;
        }

        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
 
            if(mp.find(arr[i])!=mp.end()){
                len=max(len,i-mp[arr[i]]);
            }
            
            if(mp.find(arr[i])==mp.end()){
                mp[arr[i]]=i;
            }
        }
        return len;
    }
};

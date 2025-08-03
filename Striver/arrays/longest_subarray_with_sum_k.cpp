//Brute force you know already



//Better:
//Hashing,  o(nlogn) - time   o(n)-space
//you know, you store the prefix sum as key in map one by one along with the index as value.
//Initially , you store mp[0]=-1;
//then at every time you do,arr[i]+=arr[i-1];
// if(sum-arr[i] is present in map) we do len=max(len,i-mp[sum-arr[i]]);
// we store arr[i],i in map but before that, if arr[i] is already present no need to store it,
//beacuse if it is already presnt means , it will have a shorter index than the current one, if we update it to current
// we may lose a larger subarray with sum k, for ex:- 10,-2,2,5,3  k=8  at index 2,you would already have 10 in your map,so
// you change its value to 2, you will just 5,3 as the subarray not -2,2,5,3 which is larger.


class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<long long,int> mp;
        mp[0]=-1;
        int len=0;
        if(arr[0]==k){
            len=1;
        }
        
        mp[arr[0]]=0;
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
            int rem=arr[i]-k;
            
            if(mp.find(rem)!=mp.end()){
                len=max(len,i-mp[rem]);
            }
            
            if(mp.find(arr[i])==mp.end()){
                mp[arr[i]]=i;
            }
        }
        return len;
    }
};


//the above is the most optimal for the array conatining 0s,+ves and -ves





//but we have an more optimal for the array containg only 0s and +ves
//Two pointer approach:- //its more like a sliding window......
// both initially points to 0th index, take sum=arr[0];
// move second pointer ahead and keep adding the ele, if sum==k, store the length and move ahaed
// if sum>k, you need to shrink your window by increasing your first pointer till your sum get equal to or smaler tahn k;
//thats it


class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int left=0,right=0;
        int sum=arr[0];
        int maxLen=0;
        while(right<n){
            while(left<=right && sum>k){  // left>right -> hmara subarray vahi tak ka hi hai.  or  sum<=k
                sum-=arr[left]; 
                left++;
            }
            if(sum==k){        //updating the maxlen
              maxLen=max(maxLen,right-left+1);
            }
            right++;         //move ahead
            if(right<n) sum+=arr[right];  //may be we r on the last index  and we move ahead, to handle it we use this condition
        }
        return maxLen;
    }
};
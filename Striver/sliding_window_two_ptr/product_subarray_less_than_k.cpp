// the function we made in bunary subarrsy sum
// that function calculate the subarray with sum at most k
// here we just need to do product and less than k
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) return 0;
        int lo=0,hi=0,cnt=0,product=1,n=nums.size();
       
        while(hi<n){
           product*=nums[hi];
           while(lo<=hi && product>=k){  //think about [1,1,1] k=1
            product/=nums[lo];
            lo+=1;
           }
           if(product<k){
              cnt+=(hi-lo+1);
           }
           
           hi+=1;
        }
        return cnt;
    }





// i mean for every ele, we can check till which point the condtion in true, since the array is made sorted , we can apply BS
//1.Find the left-most position in the list where we can make elements equal to a chosen number using binary search.
//2.Use prefix sums for quick calculations, and the answer is the maximum number of operations possible within the given limit.
    class Solution {
      public:
          int findBestIndex(int i, int k, const vector<int>& nums, const vector<long>& prefix) {
              int target = nums[i];
              int left = 0, right = i, best = i;
              
              while (left <= right) {
                  int mid = (left + right) / 2;
                  long count = i - mid + 1;
                  long finalSum = count * target;
                  long originalSum = prefix[i] - prefix[mid] + nums[mid];
                  long operationsRequired = finalSum - originalSum;
                  
                  if (operationsRequired > k) {
                      left = mid + 1;
                  } else {
                      best = mid;
                      right = mid - 1;
                  }
              }
              
              return i - best + 1;
          }
          
          int maxFrequency(vector<int>& nums, int k) {
              sort(nums.begin(), nums.end());
              
              vector<long> prefixSums;
              prefixSums.push_back(nums[0]);
              
              for (int i = 1; i < nums.size(); i++) {
                  prefixSums.push_back(nums[i] + prefixSums.back());
              }
              
              int maxOperations = 0;
              for (int i = 0; i < nums.size(); i++) {
                  maxOperations = max(maxOperations, findBestIndex(i, k, nums, prefixSums));
              }
              
              return maxOperations;
          }
      };


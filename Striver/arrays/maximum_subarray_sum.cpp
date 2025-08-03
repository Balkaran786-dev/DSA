//Bruteforce  o(n^2) time o(1) space
//just check the sum of all possible subarrays and store the maximum one in sum
//   for(i=0 to i=n)
//          sum=0;
//       for(j=i to j=n)
//           sum+=v[i]
//           if(sum>maxi) store sum in maxi




//Optimal approach o(n) time  o(1) space
//Kandane's algo

//add the given ele to sum , if sum>maxi update maxi , if you see than sum<0  means 
// it will anyway be decreasing me sum , it won't be contributing to increase my sum,
//so it's better to not add it, so we make sum=0.... 
//agr by chance ho ki humara age jakar hamesha -ve hi ata rhe, so we would anyway get our ans from maxi


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];

            if(sum>maxi){
               maxi=sum;
            }

            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};


//if we want to print the subarray with  maximum sum...
//you must know that, acc to kadane's algo, whenever sum=0, you start off with a new subarray.
//if your sum>maxi , then   ansStart=start and ansEnd=i...
class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int sum=0;
        int start;
        int ansStart=-1;
        int ansEnd=-1;
        for(int i=0;i<n;i++){ 
            if(sum==0) start=i;  //this is just to see that yes from here our new subarray starts,but we can't conider it in ans always, only consider in ans when sum>maxi....
            sum+=nums[i];
                              //why we have taken ansStart
            if(sum>maxi){    //take ex of -2,-3,-4 you initilise start=0 and if you want not have ansStart lets say,
                             // you just update ansEnd, but again at next ele , your sum will be zero so, it will update your start, but since
                             // in the upcoming ele, your sum remain < maxi , ansEnd remains same as 0, hence at the end your start will be at 2 and ansEnd=0 which will mess up.

               ansStart=start;
               ansEnd=i;
               maxi=sum;
            }

            if(sum<0){
                sum=0;
            }
        }
        
        vector<int> vec;
        for(int i=ansStart;i<=ansEnd;i++){
            vec.push_back(nums[i]);
        }
        return vec;
    }
};




//maximum absolute sum of a subarray
class Solution {
public:
    int minSubArray(vector<int> &nums){
           int n=nums.size();
           int maxi=INT_MAX;
           int sum=0;
           for(int i=0;i<n;i++){
            sum+=nums[i];

            if(sum<maxi){
                maxi=sum;
            }

            if(sum>0) sum=0;
            
           }

           return maxi;
    }
    int maxSubArray(vector<int> &nums){
           int n=nums.size();
           int maxi=INT_MIN;
           int sum=0;
           for(int i=0;i<n;i++){
            sum+=nums[i];

            if(sum>maxi){
                maxi=sum;
            }
            if(sum<0) sum=0;
           }

           return maxi;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        
        int max_sum=maxSubArray(nums);
        int min_sum=minSubArray(nums);
        return max(max_sum,abs(min_sum));
    }
};
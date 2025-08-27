//1st solution using maps..
//o(nlogm)+o(n) Time
//o(m) space


//2nd solution using bits manipulation  o(32*N) time , o(1) space
// for ex we have,i have exolained in copy. and code given in copy.



//3rd solution, sort the array  o(nlogn)+o(N/3) time    space o(logn) while doing sorting internally
// now we know all numbers are present in group of 3, except the one unique ele,
// if we start from idx=1, its previous ele should be equal to it, if not return it,
// move ahead the idx by 3,
// if not able to find the unique ele even after traversing the whole array,
// it must be present at the end. hence return arr[n-1];
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<n;i+=3){
           if(nums[i]!=nums[i-1]){
            return nums[i-1];
           }
        }
        return nums[n-1];
    }
};

// how this better than 2nd because there it always take 32, but here logn can't become 32 for that n=2^32 not possible





//4th solution. not very intuitive
//we make two buckets
//ones and twos.
//a number goes in one,if it is not in twos  (nums[i]^ones) & (~twos)
//a number goes in two,if it is not in ones  (nums[i]^twos) & (~ones)

// why used ^, why not | beacuse if we already have 2 in ones and again 2 comes 2|2 gives 2 as true.but we need to have 0,then only we would be able to place it in 2.
// why used &, because to make true, we want both cond to be true.
// why used ~, beacuse we want that it should not be present in ones or twos.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int twos=0,ones=0;
        for(int i=0;i<n;i++){
            ones=(nums[i]^ones)&(~twos);
            twos=(nums[i]^twos)&(~ones);
        }
        return ones;
    }
};
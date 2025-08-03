/*
tracker ko move krenge when you get any non zero ele, and then tracker ki value pe(idex pe) 
voh non zero elem likh denge,
do this till the end,
then trcaker ki value+1 se lekar jita nums ka size hoga-1 tak 0 bhar dnege..
*/


class Solution{
public:
 void moveZeroes(vector<int>&nums){
  int lastNonZeroIndex=0;

  for(int i=0;i<nums.size();i++){
   if(nums[i]!=0){
    nums[lastNonZeroIndex++]=nums[i];
   }
  }
  for(int i=lastNonZeroIndex;i<nums.size();i++){
   nums[i]=0;
  }
 }
};


//another approach..

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int j=-1;  //placing the j at the first 0 only.
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        
        if(j==-1) return;
        // we will keep our j at our first 0 in the nums
        // if any non_zero ele comes,we need to have it before zero, so we swap it with j and move j by 1, 
        // j still be at our first 0 in the array.
        for(int i=j+1;i<n;i++){
            if(nums[i]!=0){
                  swap(nums[i],nums[j]);
                  j++;
            }
        }
        return;
    }
};
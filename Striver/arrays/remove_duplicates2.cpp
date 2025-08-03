/*
Intially, count=1, i=0,j=1->n-1
if count==1
  then if num[i]==num[j] count=2,i++, num[i]=num[j];
       else  i++, num[i]=num[j];

if count==2
  then if num[i]==num[j] continue;
       else i++, num[i]=num[j],count=1.   //beacuse we are starting comapring a new ele now..
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1;
        int i=0;
        for(int j=1;j<nums.size();j++){

            switch (count){
                case 1:    // jab count 1 hai and agla ele is equal to previous or it is different....
                 if(nums[i]==nums[j]){
                    i++;
                    nums[i]=nums[j];
                    count=2;
                 }
                 else{
                    i++;
                    nums[i]=nums[j];
                 }
                 break;
                case 2:     // count == 2 and the current ele is not equal to ith index ele or may be it is equal..
                 if(nums[i]!=nums[j]){
                    i++;
                    nums[i]=nums[j];
                    count=1;
                 }
                 break;
                default:
                 cout<<"nothing";
                 break;
            }
        }
        return i+1;
    }
};
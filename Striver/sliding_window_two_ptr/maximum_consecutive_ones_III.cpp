class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int length=0;
        int n=nums.size();
        int lo=0;
        int hi=0;

        int zeroes=0;

        //ya toh mera pehle hi 1 ho ya fer agr zero hai , toh mera k should be >=1..then only I will be able to consider it in my substring..
        if(nums[0]==1) length=1;

        else if(nums[0]==0 && k>=1){
            length=1;
            zeroes=1;
        }

        else{     // if k==0 then mujhe start hi apni substring kisi 1 se krni pdegi
            while(lo<n && nums[lo]==0){
                lo++;
                hi++;
            }
        }


        hi+=1;
        while(hi<n){
            if(nums[hi]==0){
                 zeroes+=1; 
                 if(zeroes<=k){  //means ,that many zeroes can be flipped to 1s.
                    length=max(length,hi-lo+1);
                 }

                 else{   //shortening my window
                    while(zeroes>k){
                        if(nums[lo]==0){
                            zeroes--;
                        }
                        lo++;
                    }
                 }
            }

            else{
                length=max(length,hi-lo+1); 
            }
            hi+=1;
        }
        return length;
    }
};
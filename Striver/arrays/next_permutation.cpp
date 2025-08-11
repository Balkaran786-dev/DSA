
/*
Bruteforce:- 0(N!*N) approx time
1. Generate all possible permutations in sorted order.
2. linear search for the given permutation in all of these.
3. then return its just next permutation
*/



/*
Better :
Use STL, next_permutation(arr.begin(),arr.end());
*/






/*
optimal:-
Intitution:-
1. Find the longest prefix match.  start from back, when ever you see,arr[i]<arr[i+1],
that is the break point.
Also, if you r not able to find any break point , means your whole array is in the dec order,
that means that is the last permutation from all possible ones, now to get to the first,just reverse it and return;

2. Find the just larger ele to this break ele, for that , start iterating from back,because
ur array after the break ele must be in decresing order, so,whichever ele is the first ele larger to 
break ele from back, will be the  just larger ele to the break ele,

3.swap that just larger ele with break ele, and after it, you want to make the number as cloaser to the original one,
you already swapped the break ele and made it a lill larger to the given permuatation, now to make it as close as possible to original
the array after the break ele needs to be in sorted order, you just reveres it beacuse it is already in dec order even after swapping
 */


class Solution {
public:

    void nextPermutation(vector<int>& nums) {
        int idx=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        int break_ele=nums[idx];
        for(int i=n-1;i>=idx-1;i--){
            if(nums[i]>break_ele){
                swap(nums[i],nums[idx]);
                break;
            }
        }

        reverse(nums.begin()+idx+1,nums.end());
        return;
    }
};



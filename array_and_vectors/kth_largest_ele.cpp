#include<bits/stdc++.h>  //it runs correct for distinct elements
                        //if we have similar ele too, kth largest will be the kth element from ending if they are arranged in a sorted order.
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unordered_set<int> prev;
        int first_larg=INT_MIN;
        int second_larg=INT_MIN;
        int i=0;
        while(i!=k-1){
            for(int j=0;j<nums.size();j++){
                    if(!prev.count(nums[j])){
                        if(nums[j]>first_larg){
                            second_larg=first_larg;
                            first_larg=nums[j];
                        }
                        else if(nums[j]>second_larg) second_larg=nums[j];
                    }
            }
            prev.insert(first_larg);
            prev.insert(second_larg);
            first_larg=second_larg;
            second_larg=INT_MIN;
            i++;
        }
        return first_larg;
    }
};
int main(){
    vector<int> nums={3,9,4,6,1,10};
    Solution s;
    cout<<s.findKthLargest(nums,5);
    return 0;
}
/*
my dp approach
From every index , move to every possible index it can go and find the min out of all
min out of all means , so the function basically return the no_of steps .....
so from all possible indices it can reach, find the min of all of them and add plus one in it and return.
. also we use dp array where every element store the min ateps taken from that index to last index.
*/


// my own dp approach which is giving less beats.....


class Solution {
public:
    vector<int> dp;
    int get_jumps(vector<int> &nums,int idx,int n){
        if(idx==n-1){
            return 0;
        }

        if(dp[idx]!=-1) return dp[idx];

        int val=INT_MAX;
        for(int i=nums[idx];i>=1;i--){
            if(idx+i<=n-1){
                val=min(val,get_jumps(nums,idx+i,n));
            }
        }
        if(val==INT_MAX) return val;
        return dp[idx]=1+val;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,-1);
        return get_jumps(nums,0,n);
    }
};


//2. you can optimise it using 2d dp..




//3. greedy solution:-

/*
humne ranges ka concept use krenge,
first two pointers l and r on 0th index
then, jo l to r tak ke element ki jo jo bhi max_reach hogi uske maximum pe r rhenge
and usse pehle l ko r+1 pe rakh denge....
jab tak r n-1 ya fer usse aage nhi phuch jata , we will continue this loop. */

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int jumps=0;
        int max_index=INT_MIN;
        while(r<n-1){
            int i=l;
            while(i!=r+1){
                max_index=max(max_index,i+nums[i]);
                i++;
            }
            l=i;
            r=max_index;
            jumps++;
        }
        return jumps;
    }
};


// if it was not given that it is guarenteed than it will reach the end,
// we need to do this updation..

class Solution {
    public:
        
        int jump(vector<int>& nums) {
            int n=nums.size();
            int l=0,r=0;
            int jumps=0;
            int max_index=INT_MIN;
            while(l<=r && r<n-1){  // agr l bada ho gaya r se, that means humara l max_index se bhi jada ho gaya.matlab it can't reach the last index
                int i=l;
                while(i!=r+1){
                    max_index=max(max_index,i+nums[i]);
                    i++;
                }
                l=i;
                r=max_index;
                jumps++;
            }

            if(l>r) return -1; 

            return jumps;
        }
    };
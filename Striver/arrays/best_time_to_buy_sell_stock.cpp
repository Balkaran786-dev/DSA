//My approach. o(n) both space and time
class Solution {
public:
    vector<int> next_greatest_ele(vector<int> &prices,int n){
        vector<int> suffix_ele(n);
        suffix_ele[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            suffix_ele[i]=max(suffix_ele[i+1],prices[i]);
        }
        return suffix_ele;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> suffix_ele=next_greatest_ele(prices,n);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,suffix_ele[i]-prices[i]);
        }
        return ans;
    }
};


//striver approach -O(1)-space and o(n)-time

//remembering the past
//to sell on the ith day,i'll make sure that i buy on a day before ith that has to be the minimum;

//to sell on 0th day,i need to buy on that day only so,min_day=vec[0]; so no need to consider it

//start from 1st day,profit=max(profit,vec[1]-min_day);  //profit is already initilised to INT_MIN
//Also before moving further,min_day=min(min_day,ans[1]);


//OR 


//acc to leetcode,the profit should not be in -ve,
//so if you didn't got any day before where the stock val is less than the current,buy and sell on the same day,

//to implement this,
//just write the min_day_val=min(min_day_val,ans[i]); before
//then write profit=max(profit,vec[1]-min_day_val);

//it will cover up the above problem

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1) return 0;

        int profit=INT_MIN;
        int min_day_val=prices[0];
        
        for(int i=1;i<n;i++){
            min_day_val=min(prices[i],min_day_val);
            profit=max(profit,prices[i]-min_day_val);
        }

        return profit;
    }
};
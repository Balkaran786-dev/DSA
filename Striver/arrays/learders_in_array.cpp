//Brute frce quite simple o(n^2)



//optimal  o(n) + o(n) time    o(n) space which just to store ans
//for any ele, if it is greater than or equal to the max in its right subarray, it will be a leader.
class Solution {
   
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> ans;
        int prevMax=INT_MIN;
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            if(arr[i]>=prevMax){
                ans.push_back(arr[i]);
                prevMax=arr[i];
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


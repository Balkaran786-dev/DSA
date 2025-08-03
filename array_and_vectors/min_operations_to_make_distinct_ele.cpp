/*piche vale elements are more important to us,agr jaise hi hume koi element repeat
krta hua dikha,vahan tak hume elements ko remove krna pdega.abh hum nikal toh 3-3 ko hi skte hain
isiliye (i+1)/3 where i is the first index from back where ele starts repeating,
if (i+1)/3 completeley divisble,it gives us total_operations , otherwise (i+1)/3 + 1 is ans.
if all ele distinct,we return 0;
*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=n-1;i>=0;i--){
            if(mp.find(nums[i])!=mp.end()){
                int No_of_times=(i+1)/3;
                if((i+1)%3!=0){
                    No_of_times+=1;
                }
                ans=No_of_times;
                break;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};
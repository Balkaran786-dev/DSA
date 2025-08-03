// sort krna pdega hi, you kknow why,  agr ek bhut bade number mein se ek bhut shote number 
// ko minus kroge toh chances are it will be greater than k, trim down that diff, hum 
// numerically paas paas vale ele ko ek hi group mein rkhenge,for that we sort the vector

//plus you don't need to check the condition for all pairs,
// if the diff bwteen the larhgest and the smallest numebr in a group is satisfied, it is satisfied for all pairs
// if it not, than, return an empty vector of vector as ans..

class Solution {
    public:
        vector<vector<int>> divideArray(vector<int>& nums, int k) {
            int n=nums.size();
            sort(nums.begin(),nums.end());
            vector<vector<int>> ans;
            
            int i=0;
            while(i<n){
                 vector<int> temp(3);
                 temp[0]=nums[i++];
                 temp[1]=nums[i++];
                 temp[2]=nums[i++];
                 if(temp[2]-temp[0]>k){
                    ans.clear();
                    return ans;
                 }
    
                 ans.push_back(temp);
            }
    
            return ans;
        }
    };
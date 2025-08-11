//Brute_Force  o(n^2) time   o(1) space
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int cnt=1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]) cnt++;
            }
            if(cnt>nums.size()/2) return nums[i];
        }
        return -1;
    }
};



//o(nlogn) -> time  
//o(1) -> space
//we can sort the array and then traverse through it,
// here in one pass, we can get to know about the majority ele..


//Better solution  
//o(n) time in avg and best case and o(n^2) in worst case
//if we used ordered_map , time is o(nlogn)
//space o(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>nums.size()/2) return nums[i];
        }
        return -1;
    }
};


//optimal solution...
//Moore's voting algo ...
//basic intiution is that , an elemnt that occurs more than n/2 times will not be cancelled.

// two var ele and cnt=0 , if cnt =0 means we haven't considered any array, if cnt=0 , make it 1
// and ele=nums[i] now,if nums[i]==ele , cnt++  otherwise cnt--,  if you get cnt=0, that means uss 
// point tak ele can't be a majority ele since it got cancelled completely, agr majority ele hoga, it will be just one
// and kyunki voh n/2 se jada hoga, it won't get cancelled,  so since cnt is zero, we will move forward, make cnt=1 again
// and ele=nums[i] , repeat again this process, 
//if at the end , you get cnt =0 , that means no majority ele exist,
// if at the end, you get cnt!=0 , that means ele can be a majority ele, if it is given that majority ele always exist, then ele is surely the ans,
// otherwise you need to check by iterating the array again that is it correct to say ele as the majority ele.

class Solution {   //o(1) space   o(n)- time
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int ele;
        int n=nums.size();
        for(int i=0;i<n;i++){
             if(cnt==0){
                cnt=1;
                ele=nums[i];
             }
             else if(ele==nums[i]){
                cnt++;
             }
             else{
                cnt--;
             }
        }
        return ele; //cnt will akways be not zero here because it is given in the question that the majority element always exists
    }
};
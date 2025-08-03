#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(2,0);
        unordered_map<int,pair<int,bool>> mp; 
        for(auto ele:nums1){
            mp[ele].first++;
            mp[ele].second=true;
        }
        for(auto ele:nums2){
           if(mp.find(ele)!=mp.end()){
                ans[1]++;
                if(mp[ele].second==true){
                    ans[0]+=mp[ele];
                    mp[ele].second=false;
                }
           }
        }
        return ans;
    }
};
int main(){
    vector<int> ={};
    Solution s;
    s.
    return 0;
}
//Bruteforce  o(n^2)  so at max, there will be two ele having freq (> n/3)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> vec;
        for(int i=0;i<n;i++){
            if(vec.size()==0 || vec[0]!=nums[i]){
                int cnt=0;
                for(int j=i;j<n;j++){
                    if(nums[i]==nums[j]) cnt++;
                    if(cnt>n/3){
                        vec.push_back(nums[i]);
                        break;
                    }
                }
            }
        }
        return vec;
    }
};



//Better
//you know by taking hashmaps it easy... time-o(nlogn + 2n) space-o(n)



//optimal:-

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> vec;
        int cnt1=0,cnt2=0;
        int ele1=INT_MIN,ele2=INT_MIN;
        for(int i=0;i<n;i++){
            if(cnt1==0 && ele2!=nums[i]){  // yeh isilye lagaya so that dono ele1 and ele2 same na hoajye..distinct ele ko consider krenge..
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0 && ele1!=nums[i]){
                cnt2=1;
                ele2=nums[i];
            }
            else if(ele1==nums[i]){
                cnt1++;
            }
            else if(ele2==nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1)cnt1++;
            else if(nums[i]==ele2)cnt2++;
        }

        if(cnt1 > n/3) vec.push_back(ele1);
        if(cnt2 > n/3) vec.push_back(ele2);

        return vec;
    }
};
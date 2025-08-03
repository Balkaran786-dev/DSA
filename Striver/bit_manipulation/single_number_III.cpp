//1st solu  using hashmaps..



//2nd solution explained in copy
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long XOR=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            XOR^=nums[i];
        } 

        long rightmost=(XOR & (XOR-1)) ^ XOR;
        int a=0;
        int b=0;
        for(int i=0;i<n;i++){
            if(nums[i]&rightmost){
                a^=nums[i];
            }
            else{
                b^=nums[i];
            }
        }
        return {a,b};
    }
};
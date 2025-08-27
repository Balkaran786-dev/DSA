class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n=nums.size();
        int digits=0;
        int val=nums[0];
    
        while(val!=0){
            val/=10;
            digits++;
        }

        long long cnt=0;
        for(int i=0;i<digits;i++){
            vector<int> freq(10,0);
            int pos=pow(10,i);
            for(int i=0;i<n;i++){
                freq[(nums[i]/pos)%10]++;
            }
            for(int i=0;i<10;i++){
                cnt+=(1LL*freq[i]*(n-freq[i]));
            }
        }
        return cnt/2;  // kyunki har ek combination 2 times calculate hua hai, isiliye divided by 2......
    }
};
// pure recursion
// based on forming continuous substrings of a string....

class Solution {
    public:
        bool canPartition(string &s,int idx,int target,int n){
            if(idx==n){
                return target==0;
            }
    
            int sum=0;
            for(int i=idx;i<n;i++){
                sum=sum*10+(s[i]-'0');
                if(sum>target) return false;
                if(canPartition(s,i+1,target-sum,n)) return true;
            }
            return false;
        }
        int punishmentNumber(int n) {
            int square_sum=0;
            for(int i=1;i<=n;i++){
                string str=to_string(i*i);
                if(canPartition(str,0,i,str.size())){
                    square_sum+=(i*i);
                }
            }
            return square_sum;
        }
    };
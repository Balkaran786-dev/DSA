

//very similar to the chocolate prob that you did in pw, also similar to book allocation..
class Solution {
public:
    bool shipped(vector<int>& weights, int mid,int days,int n){
        int cnt=1;
        int CurrSum=0;
        for(int i=0;i<n;i++){
            if(weights[i]>mid) return false;

            else if(CurrSum+weights[i]>mid){
                cnt++;
                CurrSum=weights[i];
                if(cnt>days) return false;
            }
            else{
                CurrSum+=weights[i];
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int heaviest_wt=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
            heaviest_wt=max(heaviest_wt,weights[i]);
        }
        int lo=heaviest_wt;  //if this could be the ans, we took total days less than or equal to given days.
        int hi=sum;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(shipped(weights,mid,days,n)){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
    }
};